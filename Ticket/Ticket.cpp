//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "Ticket.h"
#include "../Exception/Exception.h"
#include <iostream>
#include <utility>

using namespace std;

Ticket::Ticket() {
    this->id = 0;
    this->code = "";
    this->day = "";
    this->price = 0.00;
    this->stock = 0;
}

Ticket::Ticket(const Ticket &ticket) {
    this->id = ticket.id;
    this->code = ticket.code;
    this->day = ticket.day;
    this->price = ticket.price;
    this->stock = ticket.stock;
}

Ticket::Ticket(int id1, string code1, string day1, float price1, int stock1) {
    this->id = id1;
    this->code = move(code1);
    this->day = move(day1);
    this->price = price1;
    this->stock = stock1;
}

void Ticket::setId(int id1) {
    this->id = id1;
}

void Ticket::setCode(string code1) {
    this->code = move(code1);
}

void Ticket::setDay(string day1) {
    this->day = move(day1);
}

void Ticket::setPrice(float price1) {
    this->price = price1;
}

void Ticket::setStock(int stock1) {
    this->stock = stock1;
}

int Ticket::getId() {
    return this->id;
}

string Ticket::getCode() {
    return this->code;
}

string Ticket::getDay() {
    return this->day;
}

float Ticket::getPrice() {
    return this->price;
}

int Ticket::getStock() {
    return this->stock;
}

Ticket::~Ticket() {
    this->id = 0;
    this->code = "";
    this->day = "";
    this->price = 0.00;
    this->stock = 0;
}

Ticket &Ticket::operator=(const Ticket &ticket) {
    this->setId(ticket.id);
    this->setCode(ticket.code);
    this->setDay(ticket.day);
    this->setPrice(ticket.price);
    this->setStock(ticket.stock);
    return *this;
}

bool compareFloatNum(double a, double b)
{

    // Correct method to compare
    // floating-point numbers
    if (abs(a - b) < 1e-9) {
        return true;
    }
    else {
        return false;
    }
}

bool Ticket::operator==(const Ticket &ticket) {
    return ((this->code == ticket.code) and (this->day == ticket.day) and (compareFloatNum(this->price, ticket.price)));
}

istream &operator>>(istream &input, Ticket &ticket) {
    cout << "Give id: ";
    input >> ticket.id;
    if(!input >> ticket.id){
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("Id must be a positive integer.");
    }
    cout << "Give code: ";
    input >> ticket.code;
    cout << "Give day: ";
    input >> ticket.day;
    cout << "Give price: ";
    input >> ticket.price;
    if(!(input >> ticket.price)){
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("Price must be a positive float.");
    }
    cout << "Give stock: ";
    input >> ticket.stock;
    if(!input >> ticket.stock){
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("Stock must be a positive integer.");
    }
    return input;
}

ostream &operator<<(ostream &output, Ticket &ticket) {
    cout << "Ticket.";
    output << ticket.getId();
    cout << ": code(";
    output << ticket.getCode();
    cout << "), day(";
    output << ticket.getDay();
    cout << "), price(";
    output << ticket.getPrice();
    cout << "), stock(";
    output << ticket.getStock();
    cout << ")" << endl;
    return output;
}


