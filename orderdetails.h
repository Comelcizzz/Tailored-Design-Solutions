#ifndef ORDERDETAILS_H
#define ORDERDETAILS_H

#include <QString>

class OrderDetails {
public:
    OrderDetails() = default;

    OrderDetails(const QString &email, const QString &addr, const QString &ph, const QString &date, const QString &greeting,
                 const QString &status = "", const QString &inspectorEmail = "", const QString &workerEmail = "",
                 const QString &workDesc = "", const QString &media = "", const QString &materials = "", const QString &customerEmail = "");

    int getOrderId() const;
    void setOrderId(int orderId);

    QString getUserEmail() const;
    void setUserEmail(const QString &userEmail);

    QString getUserName() const;
    void setUserName(const QString &userName);

    QString getAddress() const;
    void setAddress(const QString &address);

    QString getPhone() const;
    void setPhone(const QString &phone);

    QString getOrderDate() const;
    void setOrderDate(const QString &orderDate);

    QString getStatus() const;
    void setStatus(const QString &status);

    QString getUserGreeting() const;
    void setUserGreeting(const QString &userGreeting);

    QString getInspectorEmail() const;
    void setInspectorEmail(const QString &inspectorEmail);

    QString getWorkerEmail() const;
    void setWorkerEmail(const QString &workerEmail);

    QString getWorkDescription() const;
    void setWorkDescription(const QString &workDescription);

    QString getMediaLink() const;
    void setMediaLink(const QString &mediaLink);

    QString getRequiredMaterials() const;
    void setRequiredMaterials(const QString &requiredMaterials);

    QString getCustomerEmail() const;
    void setCustomerEmail(const QString &customerEmail);

    ~OrderDetails () = default;

private:
    int orderId = -1;
    QString userEmail;
    QString userName;
    QString address;
    QString phone;
    QString orderDate;
    QString status;
    QString userGreeting;
    QString inspectorEmail;
    QString workerEmail;
    QString workDescription;
    QString mediaLink;
    QString requiredMaterials;
    QString customerEmail;
};

#endif // ORDERDETAILS_H
