//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "RepoInFile.h"
#include <fstream>

RepoInFile::RepoInFile() = default;

RepoInFile::RepoInFile(const string &filename) {
    this->filename = filename;
    ifstream f(filename);
    while (!f.eof()) {
        int id, price, stock;
        string code, day;
        f >> id >> code >> day >> price >> stock;
        if(!code.empty() and !day.empty()) {
            Ticket ticket(id, code, day, price, stock);
            this->tickets.push_back(ticket);
        }
    }
    f.close();
}

RepoInFile::~RepoInFile() {
    fstream f(this->filename);
    if(f.is_open()) {
        f.close();
    }
}

void RepoInFile::saveToFile() {
    ofstream g(this->filename);
    for(Ticket &ticket: this->tickets) {
        g << ticket.getId() << " " << ticket.getCode() << " " << ticket.getDay() << " " << ticket.getPrice() << " " << ticket.getStock() << endl;
    }
    g.close();
}

void RepoInFile::addTicketInFile(Ticket &ticket) {
    this->tickets.push_back(ticket);
    this->saveToFile();
}

void RepoInFile::deleteFromFile(Ticket ticket) {
    for(int i = 0; i < this->tickets.size(); i++) {
        if(tickets[i].getId() == ticket.getId()) {
            tickets.erase(tickets.begin() + i);
        }
    }
    this->saveToFile();
}

void RepoInFile::updateFromFile(Ticket oldTicket, Ticket newTicket) {
    if(newTicket.getId() <= 0) {
        const char* msg = "Id is incorrect!";
        Exception e(msg);
        throw e;
    }
    if(newTicket.getPrice() <= 0) {
        const char* msg = "Price can't be negative or null!";
        Exception e(msg);
        throw e;
    }
    if(newTicket.getStock() <= 0) {
        const char* msg = "Stock can't be negative or null!";
        Exception e(msg);
        throw e;
    }
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == oldTicket.getId()) {
            ticket = newTicket;
        }
    }
    this->saveToFile();
}

vector<Ticket> RepoInFile::getAllFromFile() {
    return this->tickets;
}

Ticket RepoInFile::getTicketByIdFromFile(int id) {
    for(Ticket &ticket: this->tickets) {
        if(ticket.getId() == id) {
            return ticket;
        }
    }
    const char* msg = "No ticket with given id found!";
    Exception e(msg);
    throw e;
}

bool RepoInFile::find(Ticket ticket) {
    for(Ticket &ticket1: this->tickets) {
        if(ticket1 == ticket) {
            return true;
        }
    }
    return false;
}

int RepoInFile::sizeFile() {
    return (int)tickets.size();
}
