//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_SERVICE_H
#define LAB_9_LIVE_SERVICE_H

#include "../Repo/RepoInFile.h"
#include "../Repo/RepoInFileMoney.h"
#include "../TicketValidator/TicketValidator.h"
#include "../MoneyValidator/MoneyValidator.h"

class Service {
private:
    RepoInFile repoInFile;
    RepoInFileMoney repoInFileMoney;
    TicketValidator ticketValidator;
    MoneyValidator moneyValidator;
public:
    Service();
    Service(RepoInFile &repoInFile1, RepoInFileMoney &repoInFileMoney1, TicketValidator &ticketValidator1, MoneyValidator &moneyValidator1);
    void create(Ticket ticket);
    void update(Ticket oldTicket, Ticket newTicket);
    void delete1(Ticket ticket);
    Ticket getById(int id);
    vector<Ticket> getAll();
    Money getAllMoney();
    float buyTicket(int id, int noTickets, Money money);
    vector<Ticket> getAllTicketsFromGivenDay(string day);
    void updateMoney(Money money);
    ~Service();
};


#endif //LAB_9_LIVE_SERVICE_H
