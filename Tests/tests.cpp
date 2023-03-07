//
// Created by Bogdan Zarnescu on 21.04.2022.
//

#include "tests.h"
#include "../Ticket/Ticket.h"
#include <cassert>
#include "../Repo/Repo.h"
#include "../Service/Service.h"
#include <fstream>

using namespace std;

void testConstructorTicket() {
    Ticket ticket;
    assert(ticket.getId() == 0);
    assert(ticket.getCode().empty());
    assert(ticket.getDay().empty());
    assert(ticket.getPrice() == 0.0);
    assert(ticket.getStock() == 0);
}

void testConstructor2Ticket() {
    Ticket ticket(1, "SB-CJ", "Luni", 50, 100);
    assert(ticket.getId() == 1);
    assert(ticket.getCode() == "SB-CJ");
    assert(ticket.getDay() == "Luni");
    assert(ticket.getPrice() == 50);
    assert(ticket.getStock() == 100);
}

void testSetterGetter() {
    Ticket ticket;
    ticket.setId(1);
    ticket.setCode("SB-CJ");
    ticket.setDay("Luni");
    ticket.setPrice(50);
    ticket.setStock(100);
    assert(ticket.getId() == 1);
    assert(ticket.getCode() == "SB-CJ");
    assert(ticket.getDay() == "Luni");
    assert(ticket.getPrice() == 50);
    assert(ticket.getStock() == 100);
}

void testRepoAddTicket() {
    Repo repo;
    Ticket t1, t2, t3;
    t1.setId(1);
    t1.setCode("SB-CJ");
    t1.setDay("Luni");
    t1.setPrice(50);
    t1.setStock(100);

    t2.setId(2);
    t2.setCode("CJ-BV");
    t2.setDay("Marti");
    t2.setPrice(40);
    t2.setStock(120);

    t3.setId(3);
    t3.setCode("CJ-GL");
    t3.setDay("Miercuri");
    t3.setPrice(100);
    t3.setStock(150);

    repo.addTicket(t1);
    repo.addTicket(t2);
    repo.addTicket(t3);
    assert(repo.getAll().size() == 3);
    assert(repo.getAll()[0] == t1);
    assert(repo.getSize() == 3);
    assert(repo.getTicketById(1) == t1);
    assert(repo.getTicketById(2) == t2);
    assert(repo.getTicketById(3) == t3);
}

void testRepoDeleteTicket() {
    Repo repo;
    Ticket t1, t2, t3;
    t1.setId(1);
    t1.setCode("SB-CJ");
    t1.setDay("Luni");
    t1.setPrice(50);
    t1.setStock(100);

    t2.setId(2);
    t2.setCode("CJ-BV");
    t2.setDay("Marti");
    t2.setPrice(40);
    t2.setStock(120);

    t3.setId(3);
    t3.setCode("CJ-GL");
    t3.setDay("Miercuri");
    t3.setPrice(100);
    t3.setStock(150);

    repo.addTicket(t1);
    repo.addTicket(t2);
    repo.addTicket(t3);

    assert(repo.getSize() == 3);

    repo.deleteTicket(t2);

    assert(repo.getSize() == 2);
}

void testRepoUpdateTicket() {
    Repo repo;
    Ticket t1, t2, t3;
    t1.setId(1);
    t1.setCode("SB-CJ");
    t1.setDay("Luni");
    t1.setPrice(50);
    t1.setStock(100);

    t2.setId(2);
    t2.setCode("CJ-BV");
    t2.setDay("Marti");
    t2.setPrice(40);
    t2.setStock(120);

    t3.setId(2);
    t3.setCode("CJ-GL");
    t3.setDay("Miercuri");
    t3.setPrice(100);
    t3.setStock(150);

    repo.addTicket(t1);
    repo.addTicket(t2);

    assert(repo.getTicketById(2) == t2);

    repo.modifyTicket(t2, t3);

    assert(repo.getTicketById(2) == t3);
}

void testRepoUpdateMoney() {
    RepoMoney repoMoney;
    Money money(50, 50, 50, 100, 100, 100, 200, 200, 100, 100, 100);
    repoMoney.modifyMoney(money);

    assert(repoMoney.getMoney() == money);

    Money money1(20, 20, 20, 30, 30, 30, 40, 40, 50, 50, 50);
    repoMoney.modifyMoney(money1);

    assert(repoMoney.getMoney() == money1);
}

void testServiceCreate() {
    Service service;
    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(2, "CJ-BV", "Marti", 40, 120);
    Ticket t3(3, "CJ-GL", "Miercuri", 100, 150);
    service.create(t1);
    service.create(t2);
    service.create(t3);

    assert(service.getAll().size() == 3);
    assert(service.getById(1) == t1);
}

void testServiceDelete() {
    Service service;
    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(2, "CJ-BV", "Marti", 40, 120);
    Ticket t3(3, "CJ-GL", "Miercuri", 100, 150);
    service.create(t1);
    service.create(t2);
    service.create(t3);

    assert(service.getAll().size() == 3);

    service.delete1(t1);

    assert(service.getAll().size() == 2);
}

void testServiceUpdate() {
    Service service;
    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(2, "CJ-BV", "Marti", 40, 120);
    Ticket t3(2, "CJ-GL", "Miercuri", 100, 150);
    service.create(t1);
    service.create(t2);

    assert(service.getById(2) == t2);

    service.update(t2, t3);

    assert(service.getById(2) == t3);
}

void testRepoInFileAdd() {
    remove("ticket.txt");
    fstream file;
    file.open("ticket.txt", ios::in);
    file.open("ticket.txt", ios::out);
    RepoInFile repoInFile("ticket.txt");
    Ticket ticket(1, "SB-CJ", "Luni", 50, 100);
    repoInFile.addTicketInFile(ticket);
    assert(repoInFile.getAllFromFile().size() == 1);
}

void testRepoInFileDelete() {
    remove("ticket.txt");
    fstream file;
    file.open("ticket.txt", ios::in);
    file.open("ticket.txt", ios::out);
    RepoInFile repoInFile("ticket.txt");
    Ticket ticket(1, "SB-CJ", "Luni", 50, 120);
    repoInFile.addTicketInFile(ticket);
    assert(repoInFile.getAllFromFile().size() == 1);
    repoInFile.deleteFromFile(ticket);
    assert(repoInFile.getAllFromFile().empty());
}

void testRepoInFileUpdate() {
    remove("ticket.txt");
    fstream file;
    file.open("ticket.txt", ios::in);
    file.open("ticket.txt", ios::out);
    RepoInFile repoInFile("ticket.txt");
    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(1, "CJ-BV", "Marti", 40, 120);
    repoInFile.addTicketInFile(t1);
    assert(repoInFile.getTicketByIdFromFile(1) == t1);
    repoInFile.updateFromFile(t1, t2);
    assert(repoInFile.getTicketByIdFromFile(1) == t2);
}

void testRepoInFile() {
    remove("ticketsTest.txt");
    fstream f;
    f.open("ticketsTest.txt", ios::in);
    f.open("ticketsTest.txt", ios::out);
    RepoInFile repoInFile("ticketsTest.txt");

    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(2, "CJ-BV", "Marti", 40, 120);
    Ticket t3(3, "CJ-GL", "Miercuri", 100, 150);

    repoInFile.addTicketInFile(t1);
    repoInFile.addTicketInFile(t2);
    repoInFile.addTicketInFile(t3);

    assert(repoInFile.sizeFile() == 3);
    assert(repoInFile.getTicketByIdFromFile(1) == t1);
}

void testRepoInFileMoney() {
    remove("moneyTest.txt");
    fstream f;
    f.open("moneyTest.txt", ios::in);
    f.open("moneyTest.txt", ios::out);
    RepoInFileMoney repoInFileMoney("moneyTest.txt");
    Money money(50, 50, 50, 60, 60, 60, 70, 70, 70, 70, 70);
    repoInFileMoney.updateMoneyFromFile(money);
    assert(repoInFileMoney.getMoneyFromFile() == money);
}

void testBuyTicket() {
    remove("ticketsTest.txt");
    remove("moneyTest.txt");
    fstream f;
    f.open("ticketsTest.txt", ios::in);
    f.open("ticketsTest.txt", ios::out);
    f.open("moneyTest.txt", ios::in);
    f.open("moneyTest.txt", ios::out);
    RepoInFile repoInFile("ticketsTest.txt");
    RepoInFileMoney repoInFileMoney("moneyTest.txt");

    Money money(10, 10, 10, 15, 15, 15, 27, 40, 40, 40, 40);
    repoInFileMoney.updateMoneyFromFile(money);

    TicketValidator ticketValidator(repoInFile);
    MoneyValidator moneyValidator(repoInFileMoney);

    Service service(repoInFile, repoInFileMoney, ticketValidator, moneyValidator);
    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(2, "CJ-BV", "Marti", 20, 120);
    Ticket t3(3, "CJ-GL", "Miercuri", 100, 150);

    service.create(t1);
    service.create(t2);
    service.create(t3);

    Money m1(0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    float change = service.buyTicket(1, 1, m1);
    assert(change == 0);
    assert(service.getById(1).getStock() == 99);
    m1 = Money(0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0);
    change = service.buyTicket(2, 2, m1);
    assert(change == 10);
    assert(service.getById(2).getStock() == 118);
    m1 = Money(0, 0, 0, 1, 2, 1, 0, 0, 0, 0, 0);
    change = service.buyTicket(3, 1, m1);
    assert(change == 0);
    assert(service.getById(3).getStock() == 149);
}

void testGetAllTicketsFromGivenDay() {
    remove("ticketsTeste.txt");
    fstream f;
    f.open("ticketsTeste.txt", ios::in);
    f.open("ticketsTeste.txt", ios::out);
    RepoInFile repoInFile("ticketsTeste.txt");
    RepoInFileMoney repoInFileMoney("moneyTest.txt");

    Money money = Money(10, 10, 10, 15, 15, 15, 27, 40, 50, 50, 50);
    repoInFileMoney.updateMoneyFromFile(money);

    TicketValidator ticketValidator(repoInFile);
    MoneyValidator moneyValidator(repoInFileMoney);

    Service service(repoInFile, repoInFileMoney, ticketValidator, moneyValidator);
    Ticket t1(1, "SB-CJ", "Luni", 50, 100);
    Ticket t2(2, "CJ-BV", "Marti", 40, 120);
    Ticket t3(3, "CJ-GL", "Marti", 100, 150);

    service.create(t1);
    service.create(t2);
    service.create(t3);

    vector<Ticket> tickets = service.getAllTicketsFromGivenDay("Marti");
    assert(tickets.size() == 2);
    assert(tickets[0] == t2);
    assert(tickets[1] == t3);
}

void testAll() {
    testConstructorTicket();
    testConstructor2Ticket();
    testSetterGetter();
    testRepoAddTicket();
    testRepoDeleteTicket();
    testRepoUpdateTicket();
    testRepoUpdateMoney();
    testServiceCreate();
    testServiceDelete();
    testServiceUpdate();
    testRepoInFileAdd();
    testRepoInFileDelete();
    testRepoInFileUpdate();
    testRepoInFile();
    testBuyTicket();
    testGetAllTicketsFromGivenDay();
}
