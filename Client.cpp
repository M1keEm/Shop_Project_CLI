//
// Created by micha on 18/06/2023.
//

#include "Client.h"

Client::Client(const string &firstName, const string &lastName, const string &address, const char gender) : firstName(
        firstName), lastName(lastName), address(address), gender(gender) {
}

string Client::getFirstName() const {
    return firstName;
}

string Client::getLastName() const {
    return lastName;
}

string Client::getAddress() const {
    return address;
}

char Client::getGender() const {
    return gender;
}

void Client::setFirstName(const string &firstName) {
    this->firstName = firstName;
}

void Client::setLastName(const string &lastName) {
    this->lastName = lastName;
}

void Client::setAddress(const string &address) {
    this->address = address;
}

void Client::setGender(const char gender) {
    this->gender = (char) toupper((int) gender);
}

