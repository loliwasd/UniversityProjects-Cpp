#include "order.h"

Order::Order(const QString& number, const QString& date, const QString& customer)
    : orderNumber(number), orderDate(date), customerDetails(customer) {}

QString Order::getOrderNumber() const { return orderNumber; }
QString Order::getOrderDate() const { return orderDate; }
QString Order::getCustomerDetails() const { return customerDetails; }
QVector<OrderItem> Order::getItems() const { return items; }

void Order::addItem(const QString& code, int quantity) {
    items.append({code, quantity});
}

void Order::removeItem(const QString& code) {
    for (int i = 0; i < items.size(); ++i) {
        if (items[i].itemCode == code) {
            items.remove(i);
            break;
        }
    }
}

void Order::clearItems() {
    items.clear();
}
