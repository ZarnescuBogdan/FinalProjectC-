//
// Created by Bogdan Zarnescu on 20.05.2022.
//

#ifndef LAB_9_LIVE_MONEYVALIDATOR_H
#define LAB_9_LIVE_MONEYVALIDATOR_H

#include "../Money/Money.h"
#include "../Repo/RepoInFileMoney.h"

class MoneyValidator {
private:
    Money money;
    RepoInFileMoney repoInFileMoney;
public:
    MoneyValidator();
    MoneyValidator(RepoInFileMoney &repoInFileMoney1) : repoInFileMoney(repoInFileMoney1) {};
    void validate(Money &money1);
};


#endif //LAB_9_LIVE_MONEYVALIDATOR_H
