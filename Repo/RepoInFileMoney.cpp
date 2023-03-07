//
// Created by Bogdan Zarnescu on 09.05.2022.
//

#include "RepoInFileMoney.h"
#include <fstream>

RepoInFileMoney::RepoInFileMoney() = default;

RepoInFileMoney::RepoInFileMoney(const string &filename) {
    this->filename = filename;
    ifstream f(filename);
    if(!f.eof()) {
        int bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1, coins50, coins10, coins5;
        f >> bills500 >> bills200 >> bills100 >> bills50 >> bills20 >> bills10 >> bills5 >> bills1 >> coins50 >> coins10 >> coins5;
        Money money1(bills500, bills200, bills100, bills50, bills20, bills10, bills5, bills1, coins50, coins10, coins5);
        this->money = money1;
    }
    f.close();
}

RepoInFileMoney::~RepoInFileMoney() {
    fstream f(this->filename);
    if(f.is_open()) {
        f.close();
    }
}

void RepoInFileMoney::saveToFile() {
    ofstream g(this->filename);
    g << this->money.getRon500() << " " << this->money.getRon200() << " " <<  this->money.getRon100() << " " << this->money.getRon50() << " " << this->money.getRon20() << " " << this->money.getRon10() << " " << this->money.getRon5() << " " << this->money.getRon1() << " " << this->money.getBani50() << " " << this->money.getBani10() << " " << this->money.getBani5();
    g.close();
}

void RepoInFileMoney::updateMoneyFromFile(Money &money1) {
    //if(money1.getRon500() < 0 || money1.getRon200() < 0 || money1.getRon100() < 0 || money1.getRon50() < 0 || money1.getRon20() < 0 || money1.getRon10() < 0 || money1.getRon5() < 0 || money1.getRon1() < 0 || money1.getBani50() < 0 || money1.getBani10() < 0 || money1.getBani5() < 0) {
    //    const char* msg = "Money given is incorrect!";
    //    Exception e(msg);
    //    throw e;
    //}
    this->money = money1;
    this->saveToFile();
}

Money RepoInFileMoney::getMoneyFromFile() {
    return this->money;
}
