//
// Created by Bogdan Zarnescu on 09.05.2022.
//

#ifndef LAB_9_LIVE_IREPOMONEY_H
#define LAB_9_LIVE_IREPOMONEY_H

class IRepoMoney {
protected:
    Money money;
public:
    virtual void updateMoneyFromFile(Money &money1) = 0;
    virtual Money getMoneyFromFile() = 0;
};

#endif //LAB_9_LIVE_IREPOMONEY_H
