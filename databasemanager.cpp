#include "databasemanager.h"
#include <QMessageBox>

DatabaseManager& DatabaseManager::instance(const QString& dbPath) {
    static DatabaseManager instance(dbPath);
    return instance;
}

DatabaseManager::DatabaseManager(const QString& dbPath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);

    if (!db.open()) {
        qDebug() << "Error opening database:" << db.lastError().text();
    }
}

bool DatabaseManager::isConnected() const {
    return db.isOpen();
}

QSqlDatabase DatabaseManager::getDatabase() const {
    return db;
}

DatabaseManager::~DatabaseManager() {
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::createUsersTable() {
    QSqlQuery query(db);
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "firstName TEXT NOT NULL, "
        "lastName TEXT NOT NULL, "
        "email TEXT NOT NULL UNIQUE, "
        "password TEXT NOT NULL, "
        "userType TEXT NOT NULL)"
        );

    if (!success) {
        qDebug() << "Error creating users table:" << query.lastError().text();
    }

    return success;
}

bool DatabaseManager::createCustomerOrdersTable() {
    QSqlQuery query(db);
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS customerorder ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "user_email TEXT, "
        "address TEXT, "
        "phone TEXT, "
        "orderDate TEXT, "
        "status TEXT DEFAULT 'ֲ מבנמבצ³', "
        "userGreeting TEXT, "
        "inspectorEmail TEXT DEFAULT NULL, "
        "workerEmail TEXT DEFAULT NULL, "
        "FOREIGN KEY (user_email) REFERENCES users(email))"
        );

    if (!success) {
        qDebug() << "Error creating customerorder table:" << query.lastError().text();
    }

    return success;
}

bool DatabaseManager::createInspectorOrdersTable() {
    QSqlQuery query(db);
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS inspectororders ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "customerOrderId INTEGER NOT NULL, "
        "inspectorEmail TEXT NOT NULL, "
        "mediaLink TEXT, "
        "workDescription TEXT, "
        "requiredMaterials TEXT, "
        "FOREIGN KEY (customerOrderId) REFERENCES customerorder(id), "
        "FOREIGN KEY (inspectorEmail) REFERENCES users(email))"
        );

    if (!success) {
        qDebug() << "Error creating inspectororders table:" << query.lastError().text();
    }

    return success;
}

bool DatabaseManager::createWorkerOrdersTable() {
    QSqlQuery query(db);
    bool success = query.exec(
        "CREATE TABLE IF NOT EXISTS workerorders ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "workerEmail TEXT NOT NULL, "
        "customerOrderId INTEGER NOT NULL, "
        "workDescription TEXT, "
        "mediaLink TEXT, "
        "FOREIGN KEY (customerOrderId) REFERENCES customerorder(id), "
        "FOREIGN KEY (workerEmail) REFERENCES users(email))"
        );

    if (!success) {
        qDebug() << "Error creating workerorders table:" << query.lastError().text();
    }

    return success;
}

bool DatabaseManager::saveCustomerOrder(const OrderDetails &order) {
    QSqlQuery query;
    query.prepare("INSERT INTO customerorder (user_email, address, phone, orderDate, status, userGreeting, inspectorEmail) "
                  "VALUES (:user_email, :address, :phone, :orderDate, :status, :userGreeting, :inspectorEmail)");
    query.bindValue(":user_email", order.getUserEmail());
    query.bindValue(":address", order.getAddress());
    query.bindValue(":phone", order.getPhone());
    query.bindValue(":orderDate", order.getOrderDate());
    query.bindValue(":status", order.getStatus().isEmpty() ? "Pending" : order.getStatus());
    query.bindValue(":userGreeting", order.getUserGreeting());
    query.bindValue(":inspectorEmail", order.getInspectorEmail().isEmpty() ? QVariant() : order.getInspectorEmail());

    qDebug() << "Executing query with values:"
             << order.getUserEmail()
             << order.getAddress()
             << order.getPhone()
             << order.getOrderDate()
             << order.getUserGreeting();

    if (!query.exec()) {
        qDebug() << "Failed to execute query. Error:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::loadCustomerOrders(const QString &email, QVector<OrderDetails>& orders) {
    QSqlQuery query;
    query.prepare("SELECT user_email, address, phone, orderDate, status, userGreeting, inspectorEmail, workerEmail "
                  "FROM customerorder WHERE user_email = :email");
    query.bindValue(":email", email);

    if (!query.exec()) {
        qDebug() << "Failed to load orders: " << query.lastError().text();
        return false;
    }

    while (query.next()) {
        OrderDetails order;
        order.setUserEmail(query.value("user_email").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setOrderDate(query.value("orderDate").toString());
        order.setStatus(query.value("status").toString());
        order.setUserGreeting(query.value("userGreeting").toString());
        order.setInspectorEmail(query.value("inspectorEmail").toString());
        order.setWorkerEmail(query.value("workerEmail").toString());

        orders.append(order);
    }

    return true;
}

bool DatabaseManager::loadOrdersForInspector(QList<OrderDetails>& ordersList)
{
    QSqlQuery query;
    query.prepare("SELECT id, user_email, address, phone, orderDate, status FROM customerorder WHERE status = 'Pending'");

    if (!query.exec()) {
        qDebug() << "Error loading orders:" << query.lastError().text();
        return false;
    }

    while (query.next()) {
        OrderDetails order;
        order.setOrderId(query.value("id").toInt());
        order.setUserEmail(query.value("user_email").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setOrderDate(query.value("orderDate").toString());
        order.setStatus(query.value("status").toString());

        ordersList.append(order);
    }

    return true;
}

bool DatabaseManager::takeOrderForInspector(int orderId, const QString &inspectorEmail) {
    QSqlQuery query;

    query.prepare("SELECT id FROM customerorder WHERE id = :id");
    query.bindValue(":id", orderId);
    if (!query.exec() || !query.next()) {
        qDebug() << "Order not found in the database.";
        return false;
    }

    query.prepare("UPDATE customerorder SET status = :status, inspectorEmail = :inspectorEmail WHERE id = :id");
    query.bindValue(":status", "In Progress");
    query.bindValue(":inspectorEmail", inspectorEmail);
    query.bindValue(":id", orderId);

    if (!query.exec()) {
        qDebug() << "Failed to update order status: " << query.lastError().text();
        return false;
    }

    qDebug() << "Order ID " << orderId << " status updated to 'In Progress' by inspector: " << inspectorEmail;
    return true;
}


bool DatabaseManager::updateOrderStatusForInspector(int orderId, const QString &status, const QString &inspectorEmail) {
    QSqlQuery query;

    query.prepare("SELECT COUNT(*) FROM customerorder WHERE id = :id");
    query.bindValue(":id", orderId);

    if (!query.exec() || !query.next() || query.value(0).toInt() == 0) {
        QMessageBox::warning(nullptr, "Error", "Order with the specified ID does not exist.");
        qDebug() << "Order with ID" << orderId << "not found in the database.";
        return false;
    }

    query.prepare("UPDATE customerorder SET status = :status, inspectorEmail = :inspectorEmail WHERE id = :id");
    query.bindValue(":status", status);
    query.bindValue(":inspectorEmail", inspectorEmail);
    query.bindValue(":id", orderId);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Failed to update order status. " + query.lastError().text());
        qDebug() << "Database error:" << query.lastError().text();
        return false;
    }

    qDebug() << "Order ID:" << orderId << "status updated to:" << status << "by inspector:" << inspectorEmail;
    return true;
}

bool DatabaseManager::saveDetailsForInspector(int customerOrderId, const QString &mediaLink, const QString &workDescription, const QString &requiredMaterials, const QString &inspectorEmail) {
    QSqlQuery query;

    query.prepare("UPDATE customerorder SET status = :status, inspectorEmail = :inspectorEmail WHERE id = :id");
    query.bindValue(":status", "Sent to workers");
    query.bindValue(":inspectorEmail", inspectorEmail);
    query.bindValue(":id", customerOrderId);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Failed to update customer order: " + query.lastError().text());
        return false;
    }

    query.prepare("INSERT INTO inspectororders (customerOrderId, inspectorEmail, mediaLink, workDescription, requiredMaterials) "
                  "VALUES (:customerOrderId, :inspectorEmail, :mediaLink, :workDescription, :requiredMaterials)");
    query.bindValue(":customerOrderId", customerOrderId);
    query.bindValue(":inspectorEmail", inspectorEmail);
    query.bindValue(":mediaLink", mediaLink);
    query.bindValue(":workDescription", workDescription);
    query.bindValue(":requiredMaterials", requiredMaterials);

    if (!query.exec()) {
        QMessageBox::critical(nullptr, "Error", "Failed to insert inspector order: " + query.lastError().text());
        return false;
    }

    return true;
}

bool DatabaseManager::loadInspectorOrdersForInspector(const QString &inspectorEmail, QVector<OrderDetails> &orders) {
    QSqlQuery query;

    query.prepare("SELECT DISTINCT c.id, c.user_email, c.userGreeting, c.status, c.address, c.phone, "
                  "i.workDescription, i.mediaLink, c.orderDate "
                  "FROM customerorder c "
                  "LEFT JOIN inspectororders i ON c.id = i.customerOrderId "
                  "WHERE c.status = 'In Progress' "
                  "AND c.inspectorEmail = :inspectorEmail");
    query.bindValue(":inspectorEmail", inspectorEmail);

    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Error", "Failed to load orders: " + query.lastError().text());
        return false;
    }

    if (query.size() == 0) {
        QMessageBox::information(nullptr, "No Orders", "No orders are currently in progress.");
        return true;
    }

    orders.clear();

    while (query.next()) {
        OrderDetails order;
        order.setOrderId(query.value("id").toInt());
        order.setUserEmail(query.value("user_email").toString());
        order.setUserName(query.value("userGreeting").toString());
        order.setStatus(query.value("status").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setWorkDescription(query.value("workDescription").toString());
        order.setMediaLink(query.value("mediaLink").toString());

        QDateTime createdAt = query.value("orderDate").toDateTime();
        order.setOrderDate(createdAt.toString("yyyy-MM-dd hh:mm:ss"));

        orders.append(order);
    }

    return true;
}

bool DatabaseManager::loadCompletedOrdersForInspector(const QString &inspectorEmail, QVector<OrderDetails> &orders) {
    QSqlQuery query;
    query.prepare(
        "SELECT DISTINCT c.id, c.user_email, c.userGreeting, c.status, c.address, c.phone, "
        "i.mediaLink, i.workDescription, i.requiredMaterials, c.orderDate "
        "FROM customerorder c "
        "LEFT JOIN inspectororders i ON c.id = i.customerOrderId "
        "WHERE (c.status = 'Done' OR c.status = 'Sent to workers') AND c.inspectorEmail = :inspectorEmail"
        );

    query.bindValue(":inspectorEmail", inspectorEmail);

    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Error", "Failed to load completed orders: " + query.lastError().text());
        return false;
    }

    if (query.size() == 0) {
        QMessageBox::information(nullptr, "No Orders", "No completed orders found.");
        return true;
    }

    while (query.next()) {
        OrderDetails order;
        order.setOrderId(query.value("id").toInt());
        order.setUserEmail(query.value("user_email").toString());
        order.setUserName(query.value("userGreeting").toString());
        order.setStatus(query.value("status").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setMediaLink(query.value("mediaLink").toString());
        order.setWorkDescription(query.value("workDescription").toString());
        order.setRequiredMaterials(query.value("requiredMaterials").toString());
        order.setOrderDate(query.value("orderDate").toString());

        orders.append(order);
    }

    return true;
}

bool DatabaseManager::loadAvaibleOrdersForWorkers(QList<OrderDetails>& ordersList) {
    QSqlQuery query;
    query.prepare(
        "SELECT DISTINCT co.id, co.user_email, co.address, co.phone, co.orderDate, "
        "co.status, co.userGreeting, co.inspectorEmail, "
        "i.workDescription, i.mediaLink "
        "FROM customerorder co "
        "LEFT JOIN inspectororders i ON co.id = i.customerOrderId "
        "WHERE co.status = 'Sent to workers'"
        );

    if (!query.exec()) {
        qDebug() << "Failed to load available orders:" << query.lastError().text();
        return false;
    }

    ordersList.clear();

    while (query.next()) {
        OrderDetails order;
        order.setUserEmail(query.value("user_email").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setOrderDate(query.value("orderDate").toString());
        order.setUserName(query.value("userGreeting").toString());
        order.setStatus(query.value("status").toString());
        order.setInspectorEmail(query.value("inspectorEmail").toString());
        order.setWorkDescription(query.value("workDescription").toString());
        order.setMediaLink(query.value("mediaLink").toString());
        order.setOrderId(query.value("id").toInt());

        ordersList.append(order);
    }

    return true;
}

bool DatabaseManager::loadAcceptedOrdersForWorkers(const QString& workerEmail, QList<OrderDetails>& ordersList)
{
    QSqlQuery query;

    query.prepare(
        "SELECT DISTINCT c.id, c.user_email, c.address, c.phone, i.workDescription, i.mediaLink, c.status, "
        "c.orderDate, i.requiredMaterials, i.inspectorEmail "
        "FROM customerorder c "
        "LEFT JOIN inspectororders i ON c.id = i.customerOrderId "
        "WHERE c.status = 'Accepted by workers' AND c.workerEmail = :workerEmail"
        );
    query.bindValue(":workerEmail", workerEmail);

    if (!query.exec()) {
        QMessageBox::warning(nullptr, "Error", "Failed to load accepted orders: " + query.lastError().text());
        return false;
    }

    while (query.next()) {
        OrderDetails orderDetails;
        orderDetails.setOrderId(query.value("id").toInt());
        orderDetails.setCustomerEmail(query.value("user_email").toString());
        orderDetails.setAddress(query.value("address").toString());
        orderDetails.setPhone(query.value("phone").toString());
        orderDetails.setWorkDescription(query.value("workDescription").toString());
        orderDetails.setMediaLink(query.value("mediaLink").toString());
        orderDetails.setStatus(query.value("status").toString());
        orderDetails.setOrderDate(query.value("orderDate").toString());
        orderDetails.setRequiredMaterials(query.value("requiredMaterials").toString());
        orderDetails.setInspectorEmail(query.value("inspectorEmail").toString());

        ordersList.append(orderDetails);
    }

    return true;
}

bool DatabaseManager::acceptOrderForWorkers(int orderId, const QString& workerEmail)
{
    QSqlQuery query;
    query.prepare("UPDATE customerorder SET status = :status, workerEmail = :workerEmail WHERE id = :id");
    query.bindValue(":status", "Accepted by workers");
    query.bindValue(":workerEmail", workerEmail);
    query.bindValue(":id", orderId);

    if (!query.exec()) {
        qDebug() << "Error accepting order:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::saveWorkDetailsForWorkers(int orderId, const QString& workDescription, const QString& mediaLink, const QString& workerEmail)
{
    QSqlQuery query;

    query.prepare("SELECT status FROM customerorder WHERE id = :id");
    query.bindValue(":id", orderId);
    if (!query.exec()) {
        qDebug() << "Error checking order status:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString status = query.value("status").toString();
        if (status != "Accepted by workers") {
            qDebug() << "Order is not in 'Accepted by workers' status.";
            return false;
        }
    }

    query.prepare("INSERT INTO workerorders (customerOrderId, workerEmail, workDescription, mediaLink) "
                  "VALUES (:customerOrderId, :workerEmail, :workDescription, :mediaLink)");
    query.bindValue(":customerOrderId", orderId);
    query.bindValue(":workerEmail", workerEmail);
    query.bindValue(":workDescription", workDescription);
    query.bindValue(":mediaLink", mediaLink);
    if (!query.exec()) {
        qDebug() << "Error saving work details:" << query.lastError().text();
        return false;
    }

    query.prepare("UPDATE customerorder SET status = 'Done' WHERE id = :id");
    query.bindValue(":id", orderId);
    if (!query.exec()) {
        qDebug() << "Error updating order status:" << query.lastError().text();
        return false;
    }

    return true;
}

bool DatabaseManager::getWorkDetailsForWorkers(int orderId, OrderDetails& orderDetails)
{
    QSqlQuery query;
    query.prepare("SELECT c.id, c.user_email, c.address, c.phone, c.orderDate, c.status, "
                  "i.workDescription, i.mediaLink, i.inspectorEmail "
                  "FROM customerorder c "
                  "LEFT JOIN inspectororders i ON c.id = i.customerOrderId "
                  "WHERE c.id = :orderId");
    query.bindValue(":orderId", orderId);

    if (!query.exec() || !query.next()) {
        qDebug() << "Error retrieving work details:" << query.lastError().text();
        return false;
    }

    orderDetails.setOrderId(query.value("id").toInt());
    orderDetails.setCustomerEmail(query.value("user_email").toString());
    orderDetails.setAddress(query.value("address").toString());
    orderDetails.setPhone(query.value("phone").toString());
    orderDetails.setOrderDate(query.value("orderDate").toString());
    orderDetails.setStatus(query.value("status").toString());
    orderDetails.setWorkDescription(query.value("workDescription").toString());
    orderDetails.setMediaLink(query.value("mediaLink").toString());
    orderDetails.setInspectorEmail(query.value("inspectorEmail").toString());

    return true;
}

bool DatabaseManager::loadCompletedOrdersForWorkers(const QString& workerEmail, QList<OrderDetails>& completedOrders)
{
    QSqlQuery query;
    query.prepare(
        "SELECT DISTINCT c.id, c.user_email, c.address, i.inspectorEmail, i.workDescription, i.mediaLink "
        "FROM customerorder c "
        "LEFT JOIN inspectororders i ON c.id = i.customerOrderId "
        "WHERE c.status = 'Done' AND c.workerEmail = :workerEmail"
        );
    query.bindValue(":workerEmail", workerEmail);

    if (!query.exec()) {
        qDebug() << "Error loading completed orders:" << query.lastError().text();
        return false;
    }

    while (query.next()) {
        OrderDetails orderDetails;
        orderDetails.setOrderId(query.value("id").toInt());
        orderDetails.setCustomerEmail(query.value("user_email").toString());
        orderDetails.setAddress(query.value("address").toString());
        orderDetails.setInspectorEmail(query.value("inspectorEmail").toString());
        orderDetails.setWorkDescription(query.value("workDescription").toString());
        orderDetails.setMediaLink(query.value("mediaLink").toString());

        completedOrders.append(orderDetails);
    }

    return true;
}

bool DatabaseManager::searchOrdersForInspector(const QString &searchText, QVector<OrderDetails> &orders) {
    QSqlQuery query(db);

    query.prepare(
        "SELECT c.id, c.user_email, c.userGreeting, c.status, c.address, c.phone, c.orderDate, "
        "CASE "
        "   WHEN c.status = 'Sent to workers' THEN i.workDescription "
        "   WHEN c.status = 'Done' THEN w.workDescription "
        "   ELSE NULL "
        "END AS workDescription, "
        "CASE "
        "   WHEN c.status = 'Sent to workers' THEN i.mediaLink "
        "   WHEN c.status = 'Done' THEN w.mediaLink "
        "   ELSE NULL "
        "END AS mediaLink "
        "FROM customerorder c "
        "LEFT JOIN inspectororders i ON c.id = i.customerOrderId "
        "LEFT JOIN workerorders w ON c.id = w.customerOrderId "
        "WHERE (LOWER(c.user_email) LIKE LOWER(:searchText) "
        "OR LOWER(c.address) LIKE LOWER(:searchText) "
        "OR LOWER(c.status) LIKE LOWER(:searchText)) "
        "AND (c.status = 'Done' OR c.status = 'Sent to workers')"
        );

    QString searchPattern = "%" + searchText + "%";
    query.bindValue(":searchText", searchPattern);

    qDebug() << "Executing query:" << query.executedQuery();
    qDebug() << "Bound values:" << query.boundValues();

    if (!query.exec()) {
        qDebug() << "Error executing search query:" << query.lastError().text();
        return false;
    }

    orders.clear();

    while (query.next()) {
        OrderDetails order;
        order.setOrderId(query.value("id").toInt());
        order.setUserEmail(query.value("user_email").toString());
        order.setUserName(query.value("userGreeting").toString());
        order.setStatus(query.value("status").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setWorkDescription(query.value("workDescription").toString());
        order.setMediaLink(query.value("mediaLink").toString());
        order.setOrderDate(query.value("orderDate").toString());

        qDebug() << "Loaded order:" << order.getOrderId() << order.getUserEmail() << order.getStatus();

        orders.append(order);
    }

    qDebug() << "Total orders found:" << orders.size();

    return true;
}

bool DatabaseManager::searchAvailableOrdersForWorker(const QString &searchText, QList<OrderDetails> &orders)
{
    QSqlQuery query;

    query.prepare(
        "SELECT c.id, c.user_email, c.userGreeting, c.status, c.address, c.phone, c.orderDate, "
        "CASE "
        "   WHEN c.status = 'Done' THEN w.workDescription "
        "   ELSE NULL "
        "END AS workDescription, "
        "CASE "
        "   WHEN c.status = 'Done' THEN w.mediaLink "
        "   ELSE NULL "
        "END AS mediaLink "
        "FROM customerorder c "
        "LEFT JOIN workerorders w ON c.id = w.customerOrderId "
        "WHERE (LOWER(c.user_email) LIKE LOWER(:searchText) "
        "OR LOWER(c.address) LIKE LOWER(:searchText) "
        "OR LOWER(c.status) LIKE LOWER(:searchText)) "
        "AND c.status = 'Done'"
        );

    query.bindValue(":searchText", "%" + searchText + "%");

    if (!query.exec()) {
        qDebug() << "Database error: " << query.lastError().text();
        return false;
    }

    orders.clear();
    while (query.next()) {
        OrderDetails order;
        order.setOrderId(query.value("id").toInt());
        order.setUserEmail(query.value("user_email").toString());
        order.setUserName(query.value("userGreeting").toString());
        order.setStatus(query.value("status").toString());
        order.setAddress(query.value("address").toString());
        order.setPhone(query.value("phone").toString());
        order.setWorkDescription(query.value("workDescription").toString());
        order.setMediaLink(query.value("mediaLink").toString());
        order.setOrderDate(query.value("orderDate").toString());

        orders.append(order);
    }

    return true;
}

