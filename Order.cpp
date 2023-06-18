//
// Created by micha on 18/06/2023.
//

#include "Order.h"

Order::Order(const string &productName, int quantity, double price, double vatRate, const string &orderDate,
             double totalValue, PaymentMethod paymentMethod, const string &clientName) : productName(productName),
                                                                                         quantity(quantity),
                                                                                         price(price), vatRate(vatRate),
                                                                                         orderDate(orderDate),
                                                                                         totalValue(totalValue),
                                                                                         paymentMethod(paymentMethod),
                                                                                         clientName(clientName) {

}

string Order::getProductName() const {
    return productName;
}

int Order::getQuantity() const {
    return quantity;
}

double Order::getPrice() const {
    return price;
}

double Order::getVatRate() const {
    return vatRate;
}

string Order::getOrderDate() const {
    return orderDate;
}

double Order::getTotalValue() const {
    return totalValue;
}

PaymentMethod Order::getPaymentMethod() const {
    return paymentMethod;
}

string Order::getClientName() const {
    return clientName;
}

void Order::setProductName(const string &productName) {
    this->productName = productName;
}

void Order::setQuantity(int quantity) {
    this->quantity = quantity;
}

void Order::setPrice(double price) {
    this->price = price;
}

void Order::setVatRate(double vatRate) {
    this->vatRate = vatRate;
}

void Order::setOrderDate(const string &orderDate) {
    this->orderDate = orderDate;
}

void Order::setTotalValue(double totalValue) {
    this->totalValue = totalValue;
}

void Order::setPaymentMethod(PaymentMethod paymentMethod) {
    this->paymentMethod = paymentMethod;
}

void Order::setClientName(const string &clientName) {
    this->clientName = clientName;
}

