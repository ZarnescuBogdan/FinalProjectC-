//
// Created by Bogdan Zarnescu on 20.05.2022.
//

#include "TicketValidator.h"
#include <vector>

TicketValidator::TicketValidator() = default;

void TicketValidator::validate(Ticket &ticket1) {
    vector<Exception> exceptions = {};
    if(ticket1.getId() <= 0) {
        const char* msg = "Id is incorrect!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    for(Ticket &ticket2: this->repoInFile.getAllFromFile()) {
        if(ticket2.getId() == ticket1.getId()) {
            const char* msg = "Id has already been used!";
            Exception e(msg);
            exceptions.push_back(e);
        }
    }
    if(ticket1.getDay() != "Luni" and ticket1.getDay() != "Marti" and ticket1.getDay() != "Miercuri" and
        ticket1.getDay() != "Joi" and ticket1.getDay() != "Vineri" and ticket1.getDay() != "Sambata" and
        ticket1.getDay() != "Duminica") {
        const char* msg = "Day is incorrect! It has to be one of the following: Luni, Marti, Miercuri, Joi, Vineri, Sambata, Duminica.";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(ticket1.getPrice() <= 0) {
        const char* msg = "Price can't be negative or null!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(ticket1.getStock() <= 0) {
        const char* msg = "Stock can't be negative or null!";
        Exception e(msg);
        exceptions.push_back(e);
    }
    if(exceptions.size() > 0) {
        throw exceptions;
    }
}
