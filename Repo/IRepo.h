//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_IREPO_H
#define LAB_9_LIVE_IREPO_H

#include <vector>

using namespace std;

class IRepo {
protected:
    vector<Ticket> tickets;
public:
    virtual void addTicketInFile(Ticket &ticket) = 0;
    virtual vector<Ticket> getAllFromFile() = 0;
    virtual void deleteFromFile(Ticket ticket) = 0;
    virtual void updateFromFile(Ticket oldTicket, Ticket newTicket) = 0;
    virtual Ticket getTicketByIdFromFile(int id) = 0;
};

#endif //LAB_9_LIVE_IREPO_H
