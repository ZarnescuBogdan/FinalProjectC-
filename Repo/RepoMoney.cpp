//
// Created by Bogdan Zarnescu on 09.05.2022.
//

#include "RepoMoney.h"

RepoMoney::RepoMoney() = default;

void RepoMoney::modifyMoney(Money &money1) {
    this->money = money1;
}

Money RepoMoney::getMoney() {
    return this->money;
}

RepoMoney::~RepoMoney() = default;
