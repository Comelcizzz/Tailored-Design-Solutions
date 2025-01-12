#include "orderdetails.h"

OrderDetails::OrderDetails(const QString &email, const QString &addr, const QString &ph, const QString &date, const QString &greeting,
                           const QString &status, const QString &inspectorEmail, const QString &workerEmail,
                           const QString &workDesc, const QString &media, const QString &materials, const QString &customerEmail)
    : userEmail(email), address(addr), phone(ph), orderDate(date), userGreeting(greeting),
    status(status), inspectorEmail(inspectorEmail), workerEmail(workerEmail),
    workDescription(workDesc), mediaLink(media), requiredMaterials(materials), customerEmail(customerEmail) {
}

int  OrderDetails::getOrderId() const {
    return orderId;
}

void  OrderDetails::setOrderId(int orderId) {
    this->orderId = orderId;
}

QString  OrderDetails::getUserEmail() const {
    return userEmail;
}

void  OrderDetails::setUserEmail(const QString &email) {
    this->userEmail = email;
}

QString  OrderDetails::getUserName() const {
    return userName;
}

void  OrderDetails::setUserName(const QString &name) {
    this->userName = name;
}

QString  OrderDetails::getAddress() const {
    return address;
}

void  OrderDetails::setAddress(const QString &addr) {
    this->address = addr;
}

QString  OrderDetails::getPhone() const {
    return phone;
}

void  OrderDetails::setPhone(const QString &ph) {
    this->phone = ph;
}

QString  OrderDetails::getOrderDate() const {
    return orderDate;
}

void  OrderDetails::setOrderDate(const QString &date) {
    this->orderDate = date;
}

QString  OrderDetails::getStatus() const {
    return status;
}

void  OrderDetails::setStatus(const QString &st) {
    this->status = st;
}

QString  OrderDetails::getUserGreeting() const {
    return userGreeting;
}

void  OrderDetails::setUserGreeting(const QString &greeting) {
    this->userGreeting = greeting;
}

QString  OrderDetails::getInspectorEmail() const {
    return inspectorEmail;
}

void  OrderDetails::setInspectorEmail(const QString &email) {
    this->inspectorEmail = email;
}

QString  OrderDetails::getWorkerEmail() const {
    return workerEmail;
}

void  OrderDetails::setWorkerEmail(const QString &email) {
    this->workerEmail = email;
}

QString  OrderDetails::getWorkDescription() const {
    return workDescription;
}

void  OrderDetails::setWorkDescription(const QString &desc) {
    this->workDescription = desc;
}

QString  OrderDetails::getMediaLink() const {
    return mediaLink;
}

void  OrderDetails::setMediaLink(const QString &link) {
    this->mediaLink = link;
}

QString OrderDetails::getRequiredMaterials() const {
    return requiredMaterials;
}

void OrderDetails::setRequiredMaterials(const QString &materials) {
    this->requiredMaterials = materials;
}

QString OrderDetails::getCustomerEmail() const {
    return customerEmail;
}

void OrderDetails::setCustomerEmail(const QString &email) {
    this->customerEmail = email;
}
