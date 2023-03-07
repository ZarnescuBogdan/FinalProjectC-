//
// Created by Bogdan Zarnescu on 05.05.2022.
//

#ifndef LAB_9_LIVE_MONEY_H
#define LAB_9_LIVE_MONEY_H

#include <iostream>

using namespace std;

class Money {
private:
    int ron500, ron200, ron100, ron50, ron20, ron10, ron5, ron1, bani50, bani10, bani5;
public:
    Money();
    Money(int ron500, int ron200, int ron100, int ron50, int ron20, int ron10, int ron5, int ron1, int bani50, int bani10, int bani5);
    int getRon500();
    int getRon200();
    int getRon100();
    int getRon50();
    int getRon20();
    int getRon10();
    int getRon5();
    int getRon1();
    int getBani50();
    int getBani10();
    int getBani5();
    void setRon500(int ron500);
    void setRon200(int ron200);
    void setRon100(int ron100);
    void setRon50(int ron50);
    void setRon20(int ron20);
    void setRon10(int ron10);
    void setRon5(int ron5);
    void setRon1(int ron1);
    void setBani50(int bani50);
    void setBani10(int bani10);
    void setBani5(int bani5);
    Money &operator=(const Money& money);
    bool operator==(const Money& money);
    friend istream& operator>>(istream& input, Money &money);
    friend ostream& operator<<(ostream& output, Money &money);
    ~Money();
};


#endif //LAB_9_LIVE_MONEY_H
