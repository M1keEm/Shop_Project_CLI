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

    void EditOrder();

    void displayOrders();

    void displayProducts();

    void loadProductsFromFile();

    void SaveOrdersToFile();

    void menu();

};


#endif //SHOP_PROJECT_CLI_PROGRAM_H
