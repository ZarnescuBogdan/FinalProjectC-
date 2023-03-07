//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_UI_H
#define LAB_9_LIVE_UI_H

#include "../Service/Service.h"

class UI {
private:
    Service service;
public:
    UI();
    UI(Service &service1);
    ~UI();
    void runMenu();
    void addTicket();
    void showAllTickets();
    void updateTicket();
    void deleteTicket();
    void buyTicket();
    void showAllTicketsFromGivenDay();
    void showAllBills();
    void updateMoney();
};


#endif //LAB_9_LIVE_UI_H
