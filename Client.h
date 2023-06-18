//
// Created by micha on 18/06/2023.
//

#ifndef SHOP_PROJECT_CLI_CLIENT_H
#define SHOP_PROJECT_CLI_CLIENT_H

#include <iostream>
#include <string>

using namespace std;

class Client {
private:
    string firstName;
    string lastName;
    string address;
    char gender;        //char, because we're going to use only M or F(or M or K in Polish)

public:
    Client(const string &firstName, const string &lastName, const string &address,
           const char gender);  //simple constructor

    string getFirstName() const;

    string getLastName() const;

    string getAddress() const;

    char getGender() const;

    void setFirstName(const string &firstName);

    void setLastName(const string &lastName);

    void setAddress(const string &address);

    void setGender(const char gender);

};


#endif //SHOP_PROJECT_CLI_CLIENT_H
