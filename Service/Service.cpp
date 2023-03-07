//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#include "Service.h"
#include <iostream>

Service::Service() = default;

Service::Service(RepoInFile &repoInFile1, RepoInFileMoney &repoInFileMoney1, TicketValidator &ticketValidator1, MoneyValidator &moneyValidator1) {
    this->repoInFile = repoInFile1;
    this->repoInFileMoney = repoInFileMoney1;
    this->ticketValidator = ticketValidator1;
    this->moneyValidator = moneyValidator1;
}

void Service::create(Ticket ticket) {
    this->ticketValidator.validate(ticket);
    this->repoInFile.addTicketInFile(ticket);
}

void Service::update(Ticket oldTicket, Ticket newTicket) {
    this->ticketValidator.validate(newTicket);
    this->repoInFile.updateFromFile(oldTicket, newTicket);
}

void Service::delete1(Ticket ticket) {
    this->repoInFile.deleteFromFile(ticket);
}

Ticket Service::getById(int id) {
    return this->repoInFile.getTicketByIdFromFile(id);
}

vector<Ticket> Service::getAll() {
    return this->repoInFile.getAllFromFile();
}

float Service::buyTicket(int id, int noTickets, Money money) {
    if(id <= 0) {
        const char* msg = "Id is incorrect!";
        Exception e(msg);
        throw e;
    }
    if(noTickets <= 0) {
        const char* msg = "The number of tickets is incorrect!";
        Exception e(msg);
        throw e;
    }
    this->moneyValidator.validate(money);
    float price = noTickets * this->repoInFile.getTicketByIdFromFile(id).getPrice();
    float sum = 500 * money.getRon500() + 200 * money.getRon200() + 100 * money.getRon100() + 50 * money.getRon50() + 20 * money.getRon20() + 10 * money.getRon10() + 5 * money.getRon5() + money.getRon1() + 0.5 * money.getBani50() + 0.1 * money.getBani10() + 0.05 * money.getBani5();
    if(this->repoInFile.find(this->repoInFile.getTicketByIdFromFile(id))) {
        if(sum < price) {
            const char* msg = "The amount introduced is not enough!";
            Exception e(msg);
            throw e;
        }
        float change = sum - price;
        float change1 = change;
        int chg500 = min((int)(change1 / 500), this->repoInFileMoney.getMoneyFromFile().getRon500());
        int newBills500 = this->repoInFileMoney.getMoneyFromFile().getRon500() - chg500 + money.getRon500();
        change1 -= 500 * chg500;

        int chg200 = min((int)(change1 / 200), this->repoInFileMoney.getMoneyFromFile().getRon200());
        int newBills200 = this->repoInFileMoney.getMoneyFromFile().getRon200() - chg200 + money.getRon200();
        change1 -= 200 * chg200;

        int chg100 = min((int)(change1 / 100), this->repoInFileMoney.getMoneyFromFile().getRon100());
        int newBills100 = this->repoInFileMoney.getMoneyFromFile().getRon100() - chg100 + money.getRon100();
        change1 -= 100 * chg100;

        int chg50 = min((int)(change1 / 50), this->repoInFileMoney.getMoneyFromFile().getRon50());
        int newBills50 = this->repoInFileMoney.getMoneyFromFile().getRon50() - chg50 + money.getRon50();
        change1 -= 50 * chg50;

        int chg20 = min((int)(change1 / 20), this->repoInFileMoney.getMoneyFromFile().getRon20());
        int newBills20 = this->repoInFileMoney.getMoneyFromFile().getRon20() - chg20 + money.getRon20();
        change1 -= 20 * chg20;

        int chg10 = min((int)(change1 / 10), this->repoInFileMoney.getMoneyFromFile().getRon10());
        int newBills10 = this->repoInFileMoney.getMoneyFromFile().getRon10() - chg10 + money.getRon10();
        change1 -= 10 * chg10;

        int chg5 = min((int)(change1 / 5), this->repoInFileMoney.getMoneyFromFile().getRon5());
        int newBills5 = this->repoInFileMoney.getMoneyFromFile().getRon5() - chg5 + money.getRon5();
        change1 -= 5 * chg5;

        int chg1 = min((int)(change1), this->repoInFileMoney.getMoneyFromFile().getRon1());
        int newBills1 = this->repoInFileMoney.getMoneyFromFile().getRon1() - chg1 + money.getRon1();
        change1 -= chg1;

        int chgc50 = min((int)(change1 / 0.5), this->repoInFileMoney.getMoneyFromFile().getBani50());
        int newCoins50 = this->repoInFileMoney.getMoneyFromFile().getBani50() - chgc50 + money.getBani50();
        change1 -= 0.5 * chgc50;

        int chgc10 = min((int)(change1 / 0.1), this->repoInFileMoney.getMoneyFromFile().getBani10());
        int newCoins10 = this->repoInFileMoney.getMoneyFromFile().getBani10() - chgc10 + money.getBani10();
        change1 -= 0.1 * chgc10;

        int chgc5 = min((int)(change1 / 0.05), this->repoInFileMoney.getMoneyFromFile().getBani5());
        int newCoins5 = this->repoInFileMoney.getMoneyFromFile().getBani5() - chgc5 + money.getBani5();
        change1 -= 0.05 * chgc5;

        Ticket ticket = this->repoInFile.getTicketByIdFromFile(id);
        Ticket newTicket = ticket;
        newTicket.setStock(newTicket.getStock() - noTickets);
        Money money1(newBills500, newBills200, newBills100, newBills50, newBills20, newBills10, newBills5, newBills1, newCoins50, newCoins10, newCoins5);
        this->repoInFile.updateFromFile(ticket, newTicket);
        this->repoInFileMoney.updateMoneyFromFile(money1);

        if(!change1) {
            return change;
        } else {
            return sum - change;
        }

    } else {
        const char* msg = "The ticket id is not in the list!";
        Exception e(msg);
        throw e;
    }
}

vector<Ticket> Service::getAllTicketsFromGivenDay(string day) {
    if(day != "Luni" and day != "Marti" and day != "Miercuri" and day != "Joi" and
        day != "Vineri" and day != "Sambata" and day != "Duminica") {
        const char* msg = "Day is incorrect! It has to be one of the following: Luni, Marti, Miercuri, Joi, Vineri, Sambata, Duminica.";
        Exception e(msg);
        throw e;
    }
    vector<Ticket> tickets;
    for(Ticket &ticket: this->repoInFile.getAllFromFile()) {
        if(ticket.getDay() == day) {
            tickets.push_back(ticket);
        }
    }
    return tickets;
}

Money Service::getAllMoney() {
    return this->repoInFileMoney.getMoneyFromFile();
}

void Service::updateMoney(Money money) {
    this->moneyValidator.validate(money);
    this->repoInFileMoney.updateMoneyFromFile(money);
}

Service::~Service() = default;
