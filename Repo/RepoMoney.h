//
// Created by Bogdan Zarnescu on 09.05.2022.
//

#ifndef LAB_9_LIVE_REPOMONEY_H
#define LAB_9_LIVE_REPOMONEY_H

#include "../Money/Money.h"
#include "../Exception/Exception.h"

class RepoMoney {
protected:
    Money money;
public:
    RepoMoney();
    void modifyMoney(Money &money1);
    Money getMoney();
    ~RepoMoney();
};


#endif //LAB_9_LIVE_REPOMONEY_H
