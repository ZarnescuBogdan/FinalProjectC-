//
// Created by Bogdan Zarnescu on 09.05.2022.
//

#ifndef LAB_9_LIVE_REPOINFILEMONEY_H
#define LAB_9_LIVE_REPOINFILEMONEY_H

#include "RepoMoney.h"
#include "IRepoMoney.h"
#include <string>

using namespace std;

class RepoInFileMoney : public IRepoMoney {
private:
    string filename;
public:
    RepoInFileMoney();
    RepoInFileMoney(const string &filename);
    ~RepoInFileMoney();
    void updateMoneyFromFile(Money &money1) override;
    Money getMoneyFromFile() override;
    void saveToFile();

};


#endif //LAB_9_LIVE_REPOINFILEMONEY_H
