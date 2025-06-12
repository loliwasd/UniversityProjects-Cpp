#ifndef ORDER_H
#define ORDER_H

#include <QString>
#include <QVector>

struct OrderItem {
    QString itemCode;
    int quantity;
};

class Order {
private:
    QString orderNumber;
    QString orderDate;
    QString customerDetails;
    QVector<OrderItem> items;

public:
    Order(const QString& number = "", const QString& date = "", const QString& customer = "");

    QString getOrderNumber() const;
    QString getOrderDate() const;
    QString getCustomerDetails() const;
    QVector<OrderItem> getItems() const;

    void addItem(const QString& code, int quantity);
    void removeItem(const QString& code);
    void clearItems();
};

#endif // ORDER_H
