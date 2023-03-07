//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_REPOINFILE_H
#define LAB_9_LIVE_REPOINFILE_H

#include "Repo.h"
#include "IRepo.h"

class RepoInFile : public IRepo {
private:
    string filename;
public:
    RepoInFile();
    RepoInFile(const string &filename);
    ~RepoInFile();
    void addTicketInFile(Ticket &ticket) override;
    vector<Ticket> getAllFromFile() override;
    void deleteFromFile(Ticket ticket) override;
    void updateFromFile(Ticket oldTicket, Ticket newTicket) override;
    Ticket getTicketByIdFromFile(int id) override;
    void saveToFile();
    bool find(Ticket ticket);
    int sizeFile();
};


#endif //LAB_9_LIVE_REPOINFILE_H
