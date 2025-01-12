include "user.h"

User::User(const QString& dbPath) {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    id = -1;
}

User::~User() {
    if (db.isOpen()) {
        db.close();
    }
}

void User::save() {
    if (!db.open()) {
        qDebug() << "Cannot open database:" << db.lastError().text();
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO users (firstName, lastName, address, date, time, description, contactInfo)"
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(fName);
    query.addBindValue(lName);
    query.addBindValue(address);
    query.addBindValue(date);
    query.addBindValue(time);
    query.addBindValue(description);
    query.addBindValue(contactInfo);

    if (!query.exec()) {
        qDebug() << "Error inserting user:" << query.lastError().text();
    }
    else {
         id = query.lastInsertId().toInt();
    }

    db.close();
}

QString User::getFirstName() const {
    return fName;
}

QString User::getLastName() const {
    return lName;
}

void User::addMeasurement(const QString& measurement) {
    measurements.append(measurement);
}

QList<QString> User::getMeasurements() const {
    return measurements;
}

QString User::getAddress() const {
    return address;
}

QString User::getDate() const {
    return date;
}

QString User::getTime() const {
    return time;
}

QString User::getDescription() const {
    return description;
}

QString User::getContactInfo() const {
    return contactInfo;
}

void User::setAddress(const QString& address) {
    if (!address.isEmpty()) {
        this->address = address;
    } else {
        qDebug() << "Invalid address: Address cannot be empty.";
    }
}

void User::setDate(const QString& date) {
    QRegularExpression dateRegex("\\d{4}-\\d{2}-\\d{2}");
    if (dateRegex.match(date).hasMatch()) {
        this->date = date;
    } else {
        qDebug() << "Invalid date: Date must be in the format YYYY-MM-DD.";
    }
}

void User::setTime(const QString& time) {
    QRegularExpression timeRegex("\\d{2}:\\d{2}");
    if (timeRegex.match(time).hasMatch()) {
        this->time = time;
    } else {
        qDebug() << "Invalid time: Time must be in the format HH:MM.";
    }
}

void User::setDescription(const QString& description) {
    if (!description.isEmpty()) {
        this->description = description;
    } else {
        qDebug() << "Invalid description: Description cannot be empty.";
    }
}

void User::setContactInfo(const QString& contactInfo) {
    QRegularExpression emailRegex("^[\\w-\\.]+@([\\w-]+\\.)+[\\w-]{2,4}$");
    if (emailRegex.match(contactInfo).hasMatch()) {
        this->contactInfo = contactInfo;
    } else {
        qDebug() << "Invalid contact info: Must be a valid email address.";
    }
}
