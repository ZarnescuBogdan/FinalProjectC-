//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "Money.h"
#include "../Exception/Exception.h"
#include <iostream>


using namespace std;

Money::Money() {
    this->ron500 = 10;
    this->ron200 = 10;
    this->ron100 = 10;
    this->ron50 = 15;
    this->ron20 = 15;
    this->ron10 = 15;
    this->ron5 = 25;
    this->ron1 = 40;
    this->bani50 = 100;
    this->bani10 = 100;
    this->bani5 = 100;
}

Money::Money(int ron500, int ron200, int ron100, int ron50, int ron20, int ron10, int ron5, int ron1, int bani50, int bani10, int bani5) {
    this->ron500 = ron500;
    this->ron200 = ron200;
    this->ron100 = ron100;
    this->ron50 = ron50;
    this->ron20 = ron20;
    this->ron10 = ron10;
    this->ron5 = ron5;
    this->ron1 = ron1;
    this->bani50 = bani50;
    this->bani10 = bani10;
    this->bani5 = bani5;
}

int Money::getRon500() {
    return this->ron500;
}

int Money::getRon200() {
    return this->ron200;
}

int Money::getRon100() {
    return this->ron100;
}

int Money::getRon50() {
    return this->ron50;
}

int Money::getRon20() {
    return this->ron20;
}

int Money::getRon10() {
    return this->ron10;
}

int Money::getRon5() {
    return this->ron5;
}

int Money::getRon1() {
    return this->ron1;
}

int Money::getBani50() {
    return this->bani50;
}

int Money::getBani10() {
    return this->bani10;
}

int Money::getBani5() {
    return this->bani5;
}

void Money::setRon500(int ron500) {
    this->ron500 = ron500;
}

void Money::setRon200(int ron200) {
    this->ron200 = ron200;
}

void Money::setRon100(int ron100) {
    this->ron100 = ron100;
}

void Money::setRon50(int ron50) {
    this->ron50 = ron50;
}

void Money::setRon20(int ron20) {
    this->ron20 = ron20;
}

void Money::setRon10(int ron10) {
    this->ron10 = ron10;
}

void Money::setRon5(int ron5) {
    this->ron5 = ron5;
}

void Money::setRon1(int ron1) {
    this->ron1 = ron1;
}

void Money::setBani50(int bani50) {
    this->bani50 = bani50;
}

void Money::setBani10(int bani10) {
    this->bani10 = bani10;
}

void Money::setBani5(int bani5) {
    this->bani5 = bani5;
}

Money &Money::operator=(const Money &money) {
    this->setRon500(money.ron500);
    this->setRon200(money.ron200);
    this->setRon100(money.ron100);
    this->setRon50(money.ron50);
    this->setRon20(money.ron20);
    this->setRon10(money.ron10);
    this->setRon5(money.ron5);
    this->setRon1(money.ron1);
    this->setBani50(money.bani50);
    this->setBani10(money.bani10);
    this->setBani5(money.bani5);
    return *this;
}

bool Money::operator==(const Money &money) {
    return ((this->ron500 == money.ron500) and (this->ron200 == money.ron200) and (this->ron100 == money.ron100) and (this->ron50 == money.ron50) and (this->ron20 == money.ron20) and (this->ron10 == money.ron10) and
            (this->ron5 == money.ron5) and (this->ron1 == money.ron1) and (this->bani50 == money.bani50) and (this->bani10 == money.bani10) and (this->bani5 == money.bani5));
}

istream &operator>>(istream &input, Money &money) {
    cout << "Enter the amount of money(500RON, 200RON, 100RON, 50RON, 20RON, 10RON, 5RON, 1RON, 50Bani, 10Bani, 5Bani), in order: " << endl;
    cout << "Give the bills500: ";
    input >> money.ron500;
    if (!input >> money.ron500) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("500RON must be a positive integer.");
    }
    cout << "Give the bills200: ";
    input >> money.ron200;
    if (!input >> money.ron200) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("200RON must be a positive integer.");
    }
    cout << "Give the bills100: ";
    input >> money.ron100;
    if (!input >> money.ron100) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("100RON must be a positive integer.");
    }
    cout << "Give the bills50: ";
    input >> money.ron50;
    if (!input >> money.ron50) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("50RON must be a positive integer.");
    }
    cout << "Give the bills20: ";
    input >> money.ron20;
    if (!input >> money.ron20) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("20RON must be a positive integer.");
    }
    cout << "Give the bills10: ";
    input >> money.ron10;
    if (!input >> money.ron10) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("10RON must be a positive integer.");
    }
    cout << "Give the bills5: ";
    input >> money.ron5;
    if (!input >> money.ron5) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("5RON must be a positive integer.");
    }
    cout << "Give the bills1: ";
    input >> money.ron1;
    if (!input >> money.ron1) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("1RON must be a positive integer.");
    }
    cout << "Give the coins50: ";
    input >> money.bani50;
    if (!input >> money.bani50) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("50Bani must be a positive integer.");
    }
    cout << "Give the coins10: ";
    input >> money.bani10;
    if (!input >> money.bani10) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("10Bani must be a positive integer.");
    }
    cout << "Give the coins5: ";
    input >> money.bani5;
    if (!input >> money.bani5) {
        input.clear();
        input.ignore(10000, '\n');
        throw Exception("5Bani must be a positive integer.");
    }
    return input;
}

ostream &operator<<(ostream &output, Money &money) {
    cout << "The money from the bank: " << endl;
    cout << "500RON bills: ";
    output << money.getRon500();
    cout << endl << "200RON bills: ";
    output << money.getRon200();
    cout << endl << "100RON bills: ";
    output << money.getRon100();
    cout << endl << "50RON bills: ";
    output << money.getRon50();
    cout << endl << "20RON bills: ";
    output << money.getRon20();
    cout << endl << "10RON bills: ";
    output << money.getRon10();
    cout << endl << "5RON bills: ";
    output << money.getRon5();
    cout << endl << "1RON bills: ";
    output << money.getRon1();
    cout << endl << "50Bani coins: ";
    output << money.getBani50();
    cout << endl << "10Bani coins: ";
    output << money.getBani10();
    cout << endl << "5Bani coins: ";
    output << money.getBani5();
    return output;
}

Money::~Money() = default;
