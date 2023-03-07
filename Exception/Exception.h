//
// Created by Bogdan Zarnescu on 17.05.2022.
//

#ifndef LAB_9_LIVE_EXCEPTION_H
#define LAB_9_LIVE_EXCEPTION_H

#include <stdexcept>

using namespace std;

class Exception: public exception{
private:
    const char* message;
public:
    Exception(const char* message1) : message(message1) {}
    const char* what() const noexcept override {
        return this->message;
    }
};


#endif //LAB_9_LIVE_EXCEPTION_H
