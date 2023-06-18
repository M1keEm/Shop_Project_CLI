//
// Created by micha on 18/06/2023.
//

#include "Program.h"

void Program::AddNewClient() {
    string name, surname, address1;
    char gender1;
    cout << "Podaj dane klienta do dodania: \n";
    cout << "Plec: (K/M)" << endl;
    cin >> gender1;
    cout << "Imie: " << endl;
    cin >> name;
    cout << "Nazwisko: " << endl;
    cin >> surname;
    cout << "Adres: " << endl;
    cin >> address1;
    Client client(name, surname, address1, gender1);
    cout << "Klient zostal dodany do bazy danych" << endl;
}
