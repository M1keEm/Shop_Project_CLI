//
// Created by micha on 18/06/2023.
//

#ifndef SHOP_PROJECT_CLI_PROGRAM_H
#define SHOP_PROJECT_CLI_PROGRAM_H

#include "Client.h"
#include "Order.h"
#include "vector"

class Program {
private:
    vector<Client> clients;
    vector<Order> orders;
    vector<string> products;


public:
    void AddNewClient();

    void ModifyClient();

    void SaveClientsToFile();

    void AddNewOrder();

    void displayOrders();

    void displayProducts();

    void EditOrder();

    void loadProductsFromFile();

    void saveOrdersToFile();

};


#endif //SHOP_PROJECT_CLI_PROGRAM_H
