//
// Created by micha on 18/06/2023.
//

#ifndef SHOP_PROJECT_CLI_ORDER_H
#define SHOP_PROJECT_CLI_ORDER_H
#include <iostream>
#include <string>

using namespace std;

enum PaymentMethod {
    gotowka, karta, przelew, blik
};

class Order {
private:
    string productName;
    int quantity;
    double price;
    double vatRate;
    string orderDate;
    double totalValue;
    PaymentMethod paymentMethod;
    string clientName;

public:
    Order(const string &productName, int quantity, double price, double vatRate, const string &orderDate,
          double totalValue, PaymentMethod paymentMethod, const string &clientName);

    string getProductName() const;

    int getQuantity() const;

    double getPrice() const;

    double getVatRate() const;

    string getOrderDate() const;

    double getTotalValue() const;

    PaymentMethod getPaymentMethod() const;

    string getClientName() const;

    void setProductName(const string &productName);

    void setQuantity(int quantity);

    void setPrice(double price);

    void setVatRate(double vatRate);

    void setOrderDate(const string &orderDate);

    void setTotalValue(double totalValue);

    void setPaymentMethod(PaymentMethod paymentMethod);

    void setClientName(const string &clientName);
};


#endif //SHOP_PROJECT_CLI_ORDER_H
