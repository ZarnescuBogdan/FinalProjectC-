//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "UI.h"
#include <iostream>

using namespace std;

UI::UI() = default;

UI::UI(Service &service1) {
    this->service = service1;
}

void UI::runMenu() {
    bool ok = true;
    while (ok) {
        cout << endl;
        cout << "1. Add a ticket." << endl;
        cout << "2. Delete a ticket." << endl;
        cout << "3. Update a ticket." << endl;
        cout << "4. Buy a ticket." << endl;
        cout << "5. Show all tickets a from given day." << endl;
        cout << "s. Show all tickets." << endl;
        cout << "m. Show the money from the bank." << endl;
        cout << "u. Update money from the bank." << endl;
        cout << "x. Exit." << endl;
        char option;
        cout << "Give option: ";
        cin >> option;
        switch (option) {
            case '1': {
                this->addTicket();
                break;
            }
            case '2': {
                this->deleteTicket();
                break;
            }
            case '3': {
                this->updateTicket();
                break;
            }
            case '4': {
                this->buyTicket();
                break;
            }
            case '5': {
                this->showAllTicketsFromGivenDay();
                break;
            }
            case 's': {
                this->showAllTickets();
                break;
            }
            case 'm': {
                this->showAllBills();
                break;
            }
            case 'u': {
                this->updateMoney();
                break;
            }
            case 'x':
                ok = false;
                break;
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void UI::addTicket() {
    try {
        Ticket ticket;
        cin >> ticket;
        this->service.create(ticket);
    }
    catch (Exception &exception) {
        cout << exception.what();
    }
    catch (vector<Exception> &exceptions) {
        for(Exception &exception: exceptions) {
            cout << exception.what() << endl;
        }
    }
}

void UI::showAllTickets() {
    for(Ticket &ticket: this->service.getAll()) {
        cout << ticket;
    }
}

void UI::deleteTicket() {
    try {
        int id;
        cout << "Give id to be deleted: ";
        cin >> id;
        if (!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer.");
        }
        if (id <= 0) {
            //cout << "Id is incorrect!";
            throw Exception("Id is incorrect.");
        }
        int size = this->service.getAll().size();
        for (Ticket &ticket: this->service.getAll()) {
            if (ticket.getId() == id) {
                this->service.delete1(ticket);
            }
        }
        if (this->service.getAll().size() == size) {
            cout << "There is no ticket with given id!";
        }
    }
    catch (Exception &exception) {
        cout << exception.what();
    }
}

void UI::updateTicket() {
    try {
        int id;
        cout << "Give id for the ticket to be updated: ";
        cin >> id;
        if (!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer.");
        }
        if (id <= 0) {
            //cout << "Id is incorrect!";
            throw Exception("Id is incorrect.");
        }
        Ticket ticket;
        cin >> ticket;
        bool k = false;
        for (Ticket &ticket1: this->service.getAll()) {
            if (ticket1.getId() == id) {
                k = true;
                this->service.update(ticket1, ticket);
            }
        }
        if (!k) {
            cout << "Ticket id given is not in the list!";
        }
    }
    catch (Exception & exception) {
        cout << exception.what();
    }
}

void UI::buyTicket() {
    try {
        int id, noTickets;
        cout << "Give id for the ticket to be bought: ";
        cin >> id;
        if (!cin >> id) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("Id must be a positive integer.");
        }
        Ticket ticket = this->service.getById(id);
        cout << "Give the number of tickets wanted: ";
        cin >> noTickets;
        if (!cin >> noTickets) {
            cin.clear();
            cin.ignore(10000, '\n');
            throw Exception("The number of tickets must be a positive integer.");
        }
        Money money;
        cin >> money;
        float change = this->service.buyTicket(id, noTickets, money);
        if (change) {
            cout << "The maximum possible change has been made!";
        } else {
            cout << "The change has been made!";
        }
    }
    catch (Exception &exception) {
        cout << exception.what();
    }
    catch (vector<Exception> &exceptions) {
        for(Exception &exception: exceptions) {
            cout << exception.what() << endl;
        }
    }
}

void UI::showAllTicketsFromGivenDay() {
    try {
        string day;
        cout << "Give the day you are looking for: ";
        cin >> day;
        vector<Ticket> tickets = this->service.getAllTicketsFromGivenDay(day);
        for (Ticket &ticket: tickets) {
            cout << ticket;
        }
    }
    catch (Exception &exception) {
        cout << exception.what();
    }
}

void UI::showAllBills() {
    Money money = this->service.getAllMoney();
    cout << money;
}

void UI::updateMoney() {
    try {
        Money money;
        cin >> money;
        this->service.updateMoney(money);
    }
    catch (Exception &exception) {
        cout << exception.what();
    }
    catch (vector<Exception> &exceptions) {
        for(Exception &exception: exceptions) {
            cout << exception.what() << endl;
        }
    }
}

UI::~UI() = default;
