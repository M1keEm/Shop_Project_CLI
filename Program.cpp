//
// Created by micha on 18/06/2023.
//

#include "Program.h"
#include <fstream>
#include <sstream>


void Program::AddNewClient() {
    string name, surname, address1;
    char gender1;
    cout << "Podaj dane klienta do dodania: \n";
    cout << "Plec: (K/M)" << endl;
    cin >> gender1;
    while (gender1 != 'K' && gender1 != 'M') {
        cout << "Niepoprawna plec" << endl;
        cout << "Podaj plec: (K lub M)" << endl;
        cin >> gender1;
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
    while (clientNumber > clients.size() || clientNumber < 1) {
        cout << "Nie ma takiego klienta" << endl;
        cout << "Podaj nr klienta do edycji: " << endl;
        cin >> clientNumber;
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
    while (choice < 1 || choice > 5) {
        cout << "Niepoprawny wybor" << endl;
        cout << "Co chcesz zmienic? (wpisz cyfre od 1 do 4)" << endl;
        cout << "1 >>> Imie" << endl;
        cout << "2 >>> Nazwisko" << endl;
        cout << "3 >>> Adres" << endl;
        cout << "4 >>> Plec" << endl;
        cout << "5 >>> Powrot do menu" << endl;
        cin >> choice;
    }
    if (choice != 5) {
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
                }
                clients[clientNumber - 1].setGender(newGender);
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
    if (file.good()) {
        for (int i = 0; i < clients.size(); i++) {
            file << i + 1 << ";";
            file << clients[i].getFirstName() << ";";
            file << clients[i].getLastName() << ";";
            file << clients[i].getAddress() << ";";
            file << clients[i].getGender() << endl;
        }
        cout << "Zapis do pliku tekstowego przebiegl pomyslnie" << endl;
    } else {
        cout << "Blad zapisu" << endl;
    }
    //saving to binary file
    ofstream fileBinary;
    fileBinary.open("clients.dat", ios::out | ios::binary);
    if (fileBinary.good() && fileBinary.is_open()) {
        for (int i = 0; i < clients.size(); i++) {
            fileBinary.write(reinterpret_cast<char *>(&i), sizeof(int));
            fileBinary.write(reinterpret_cast<char *>(&clients[i]), clients.size());
        }
        cout << "Zapis do pliku binarnego przebiegl pomyslnie" << endl;
    } else {
        cout << "Blad zapisu" << endl;
    }
    file.close();
}

void Program::AddNewOrder() {
    string productName1, orderDate1, clientName1;
    double vat1, price1, totalValue1;
    int quantity1, clientNumber1;
    PaymentMethod paymentMethod1;

    cout << "Podaj nr klienta skladajacego zamowienie: " << endl;
    cin >> clientNumber1;
    while (clientNumber1 > clients.size() || clientNumber1 < 1) {
        cout << "Nie ma takiego klienta" << endl;
        cout << "Podaj nr klienta skladajacego zamowienie: " << endl;
        cin >> clientNumber1;
    }
    cout << "Wybrano klienta: " << clients[clientNumber1 - 1].getFirstName() << " "
         << clients[clientNumber1 - 1].getLastName() << endl;
    cout << "Podaj nazwe produktu: " << endl;
    cin >> productName1;
    cout << "Podaj ilosc: " << endl;
    cin >> quantity1;
    ifstream file1;
    file1.open("C:products.txt");
    string productNameF;
    float quantityF, priceF, valueF;
    valueF = 0;
    for (int i = 0; i < 6; i++) {
        file1 >> productNameF >> quantityF >> priceF;
        if (productName1 == productNameF) {
            price1 = priceF;
            vat1 = quantity1 * (0.23 * priceF);
            valueF += quantity1 * priceF + (quantity1 * (0.23 * priceF));
        }
    }
    cout << "Podaj sposob zaplaty: " << endl;
    cout << "1 >>> Karta" << endl;
    cout << "2 >>> Gotowka" << endl;
    cout << "3 >>> Przelew" << endl;
    cout << "4 >>> Blik" << endl;
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Niepoprawny wybor" << endl;
        cout << "Podaj sposob zaplaty: " << endl;
        cout << "1 >>> Karta" << endl;
        cout << "2 >>> Gotowka" << endl;
        cout << "3 >>> Przelew" << endl;
        cout << "4 >>> Blik" << endl;
        cin >> choice;
    }
    switch (choice) {
        case 1:
            paymentMethod1 = PaymentMethod::karta;
            break;
        case 2:
            paymentMethod1 = PaymentMethod::gotowka;
            break;
        case 3:
            paymentMethod1 = PaymentMethod::przelew;
            break;
        case 4:
            paymentMethod1 = PaymentMethod::blik;
            break;
        default:
            cout << "Niepoprawny wybor" << endl;
            break;
    }
    cout << "Podaj date zamowienia: " << endl;
    cin.ignore();
    getline(std::cin, orderDate1);
    clientName1 = clients[clientNumber1 - 1].getFirstName() + " " + clients[clientNumber1 - 1].getLastName();

    Order order(productName1, quantity1, price1, vat1, orderDate1, valueF, paymentMethod1, clientName1);
    orders.push_back(order);
    cout << "Zamowienie zostalo dodane do bazy danych" << endl;
}


void Program::displayOrders() {
    int i = 0;
    for (const auto &order: orders) {
        cout << "Nr zamowienia: " << i + 1 << endl;
        cout << "Imie i nazwisko klienta: " << order.getClientName() << endl;
        cout << "Data: " << order.getOrderDate() << endl;
        cout << "Produkt: " << order.getProductName() << endl;
        cout << "Cena: " << order.getPrice() << endl;
        cout << "Ilosc: " << order.getQuantity() << endl;
        cout << "Koszt VAT: " << order.getVatRate() << endl;
        cout << "Calkowita wartosc zamowienia: " << order.getTotalValue() << endl;
        cout << "Metoda platnosci: " << order.getPaymentMethod() << endl;
        cout << "===============================================" << endl;
        i++;
    }
}

void Program::EditOrder() {
    int index;
    string productName, orderDate, clientName;
    PaymentMethod paymentMethod;
    int quantity;
    double vatRate, price, totalValue;
    cout << "Podaj nr zamowienia do edycji: " << endl;
    cin >> index;
    while (index - 1 > orders.size() || index - 1 < 0) {
        cout << "Nie ma takiego zamowienia" << endl;
        cout << "Podaj indeks zamowienia do edycji: " << endl;
        cin >> index;
    }
    cout << "Wybrano zamowienie: \n" << endl;
    cout << "Imie i nazwisko klienta: " << orders[index - 1].getClientName() << endl;
    cout << "Data: " << orders[index - 1].getOrderDate() << endl;
    cout << "Produkt: " << orders[index - 1].getProductName() << endl;
    cout << "Cena: " << orders[index - 1].getPrice() << endl;
    cout << "Ilosc: " << orders[index - 1].getQuantity() << endl;
    cout << "Vat: " << orders[index - 1].getVatRate() << endl;
    cout << "Calkowita wartosc zamowienia: " << orders[index - 1].getTotalValue() << endl;
    cout << "Metoda platnosci: " << orders[index - 1].getPaymentMethod() << endl;
    cout << "===============================================" << endl;

    cout << "Edycja imienia: ";
    cin.ignore();
    getline(cin, clientName);

    cout << "Edycja nazwy produktu: ";
    getline(cin, productName);

    cout << "Edycja ilosci ";
    cin >> quantity;

    cout << "Edycja daty: ";
    cin.ignore();
    getline(cin, orderDate);

    cout << "Edycja metody platnosci: " << endl;
    cout << "1 >>> Karta" << endl;
    cout << "2 >>> Gotowka" << endl;
    cout << "3 >>> Przelew" << endl;
    cout << "4 >>> Blik" << endl;
    int choice;
    cin >> choice;
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4) {
        cout << "Niepoprawny wybor" << endl;
        cout << "Podaj sposob zaplaty: " << endl;
        cout << "1 >>> Karta" << endl;
        cout << "2 >>> Gotowka" << endl;
        cout << "3 >>> Przelew" << endl;
        cout << "4 >>> Blik" << endl;
        cin >> choice;
    }
    switch (choice) {
        case 1:
            paymentMethod = PaymentMethod::karta;
            break;
        case 2:
            paymentMethod = PaymentMethod::gotowka;
            break;
        case 3:
            paymentMethod = PaymentMethod::przelew;
            break;
        case 4:
            paymentMethod = PaymentMethod::blik;
            break;
        default:
            cout << "Niepoprawny wybor" << endl;
            break;
    }

    totalValue = price * quantity * (1 + vatRate);
    orders[index - 1].setProductName(productName);
    orders[index - 1].setQuantity(quantity);
    orders[index - 1].setOrderDate(orderDate);
    orders[index - 1].setTotalValue(totalValue);
    orders[index - 1].setPaymentMethod(paymentMethod);
    orders[index - 1].setClientName(clientName);

    cout << "Zmiana danych zamowienia zakonczona sukcesem" << endl;
}


void Program::loadProductsFromFile() {
    string fileName;
    ifstream inputFile("products.txt");
    if (inputFile.is_open()) {
        string product;
        while (getline(inputFile, product)) {
            products.push_back(product);
            system("cls");
        }
        cout << "Zaladowano produkty z pliku" << endl;
    } else {
        cout << "Blad podczas proby zaladowania produktow z pliku" << endl;
    }
}

void Program::SaveOrdersToFile() {
    ofstream outputFile("orders.txt");
    if (outputFile.is_open() && !orders.empty()) {
        for (const auto &order: orders) {
            outputFile << " Nazwa produktu: " << order.getProductName() << ","
                       << " Ilosc: " << order.getQuantity() << ","
                       << " Koszt VAT: " << order.getVatRate() << ","
                       << " Cena: " << order.getPrice() << ","
                       << " Data: " << order.getOrderDate() << ","
                       << " Calkowita wartosc zamowienia: " << order.getTotalValue() << ","
                       << " Metoda platnosci: " << order.getPaymentMethod() << ","
                       << " Imie i nazwisko klienta: " << order.getClientName() << endl;
        }
        cout << "Zapis do pliku zakonczyl sie powodzeniem" << endl;
    } else {
        cout << "Blad zapisu " << endl;
    }
}

void Program::displayProducts() {
    cout << "Wyswietlam dostepne produkty..." << endl;
    for (const auto &product: products) {
        cout << product << endl;
    }
}

void Program::menu() {
    int choice;
    loadProductsFromFile();
    choice = 1;
    while (choice != 0) {
        cout << "Witaj w programie do obslugi zamowien" << endl;
        cout << "Wybierz opcje z menu: " << endl;
        cout << "1 >>> Dodaj nowego klienta" << endl;
        cout << "2 >>> Zmodyfikuj klienta" << endl;
        cout << "3 >>> Dodaj nowe zamowienie" << endl;
        cout << "4 >>> Edytuj zamowienie" << endl;
        cout << "5 >>> Wyswietl produkty" << endl;
        cout << "6 >>> Wyswietl zamowienia" << endl;
        cout << "7 >>> Zapisz informacje o klientach do pliku" << endl;
        cout << "8 >>> Zapisz informacje o zamowieniach do pliku" << endl;
        cout << "0 >>> Exit" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                AddNewClient();
                break;
            case 2:
                ModifyClient();
                break;
            case 3:
                AddNewOrder();
                break;
            case 4:
                EditOrder();
                break;
            case 5:
                displayProducts();
                break;
            case 6:
                displayOrders();
                break;
            case 7:
                SaveClientsToFile();
                break;
            case 8:
                SaveOrdersToFile();
                break;
            case 0:
                cout << "Koniec dzialania programu" << endl;
                cout << "Exiting..." << endl << endl;
                break;
            default:
                cout << "Niepoprawny wybor" << endl;
                break;
        }
        system("pause");
    }
}
