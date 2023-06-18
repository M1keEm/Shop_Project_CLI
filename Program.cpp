//
// Created by micha on 18/06/2023.
//

#include "Program.h"
#include <fstream>

void Program::AddNewClient() {
    string name, surname, address1;
    char gender1;
    cout << "Podaj dane klienta do dodania: \n";
    cout << "Plec: (K/M)" << endl;
    cin >> gender1;
    while (gender1 != 'K' && gender1 != 'M') {
        cout << "Niepoprawna plec" << endl;
        cout << "Podaj plec: (K lub M)" << endl;
    }
    cout << "Imie: " << endl;
    cin >> name;
    cout << "Nazwisko: " << endl;
    cin >> surname;
    cout << "Adres: " << endl;
    cin >> address1;
    Client client(name, surname, address1, gender1);
    clients.push_back(client);
    cout << "Klient zostal dodany do bazy danych" << endl;
}

void Program::ModifyClient() {
    cout << "Podaj nr klienta do edycji: " << endl;
    int clientNumber;
    cin >> clientNumber;
    while(clientNumber>clients.size() || clientNumber<1){
        cout<<"Nie ma takiego klienta"<<endl;
        cout<<"Podaj nr klienta do edycji: "<<endl;
        cin>>clientNumber;
    }
    cout << "Co chcesz zmienic? (wpisz cyfre od 1 do 4)" << endl;
    cout << "1 >>> Imie" << endl;
    cout << "2 >>> Nazwisko" << endl;
    cout << "3 >>> Adres" << endl;
    cout << "4 >>> Plec" << endl;
    cout << "5 >>> Powrot do menu" << endl;
    int choice;
    cin >> choice;
    string newName, newSurname, newAddress;
    char newGender;
    while (choice != 5 && choice > 1 && choice < 5) {
        switch (choice) {
            case 1:
                cout << "Podaj nowe imie: " << endl;
                cin >> newName;
                clients[clientNumber - 1].setFirstName(newName);
                break;
            case 2:
                cout << "Podaj nowe nazwisko: " << endl;
                cin >> newSurname;
                clients[clientNumber - 1].setLastName(newSurname);
                break;
            case 3:
                cout << "Podaj nowy adres: " << endl;
                cin >> newAddress;
                clients[clientNumber - 1].setAddress(newAddress);
                break;
            case 4:
                cout << "Podaj nowa plec: (K/M)" << endl;
                cin >> newGender;
                if (newGender != 'K' && newGender != 'M') {
                    cout << "Podano niepoprawna plec" << endl;
                    break;
                } else clients[clientNumber - 1].setGender(newGender);
                break;
            case 5:
                cout << "Powrot do menu" << endl;
                break;
            default:
                cout << "Niepoprawny wybor" << endl;
                break;
        }
    }
}

void Program::SaveClientsToFile() {
    ofstream file;
    file.open("clients.txt");
    if(file.good()){
        for (int i = 0; i < clients.size(); i++) {
            file << i + 1 << ";";
            file << clients[i].getFirstName() << ";";
            file << clients[i].getLastName() << ";";
            file << clients[i].getAddress() << ";";
            file << clients[i].getGender() << endl;
        }
        cout << "Zapis do pliku tekstowego przebiegl pomyslnie" << endl;
    }else{
        cout << "Blad zapisu" << endl;
    }
    //saving to binary file
    ofstream fileBinary;
    fileBinary.open("clients.dat", ios:: out|ios::binary);
    if(fileBinary.good() && fileBinary.is_open()){
        for (int i = 0; i < clients.size(); i++) {
            fileBinary.write(reinterpret_cast<char*>(&i), sizeof(int));
            fileBinary.write(reinterpret_cast<char*>(&clients[i]), clients.size());
//            fileBinary.write((char*)&clients[i].getLastName(), sizeof(string));
//            fileBinary.write((char*)&clients[i].getAddress(), sizeof(string));
//            fileBinary.write((char*)&clients[i].getGender(), sizeof(char));
        }
        cout << "Zapis do pliku binarnego przebiegl pomyslnie" << endl;
    }else{
        cout << "Blad zapisu" << endl;
    }
    file.close();
}
