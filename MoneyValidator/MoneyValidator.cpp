//
// Created by Bogdan Zarnescu on 20.05.2022.
//

#include "MoneyValidator.h"
#include <vector>

MoneyValidator::MoneyValidator() = default;

void MoneyValidator::validate(Money &money1) {
    vector<Exception> exceptions = {};
    if(money1.getRon500() < 0) {
        const char* msg = "500RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon200() < 0) {
        const char* msg = "200RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon100() < 0) {
        const char* msg = "100RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon50() < 0) {
        const char* msg = "50RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon20() < 0) {
        const char* msg = "20RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon10() < 0) {
        const char* msg = "10RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon5() < 0) {
        const char* msg = "5RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getRon1() < 0) {
        const char* msg = "1RON bills must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getBani50() < 0) {
        const char* msg = "50Bani coins must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getBani10() < 0) {
        const char* msg = "10Bani coins must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(money1.getBani5() < 0) {
        const char* msg = "5Bani coins must be a positive integer!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(exceptions.size() > 0) {
        const char* msg = "Money given is incorrect!";
        Exception e(msg);
        exceptions.insert(exceptions.begin(), e);
        throw exceptions;
    }
}
