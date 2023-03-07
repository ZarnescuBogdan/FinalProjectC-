//
// Created by Bogdan Zarnescu on 20.05.2022.
//

#ifndef LAB_9_LIVE_TICKETVALIDATOR_H
#define LAB_9_LIVE_TICKETVALIDATOR_H

#include "../Ticket/Ticket.h"
#include "../Repo/RepoInFile.h"

class TicketValidator {
private:
    Ticket ticket;
    RepoInFile repoInFile;
public:
    TicketValidator();
    TicketValidator(RepoInFile &repoInFile1) : repoInFile(repoInFile1) {};
    void validate(Ticket &ticket1);
};


#endif //LAB_9_LIVE_TICKETVALIDATOR_H
