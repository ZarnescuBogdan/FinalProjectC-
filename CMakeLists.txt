cmake_minimum_required(VERSION 3.21)
project(Lab_9_live)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab_9_live main.cpp Ticket/Ticket.cpp Ticket/Ticket.h Repo/Repo.cpp Repo/Repo.h Tests/tests.h Tests/tests.cpp Service/Service.cpp Service/Service.h UI/UI.cpp UI/UI.h Repo/RepoInFile.cpp Repo/RepoInFile.h Repo/IRepo.h Money/Money.cpp Money/Money.h Repo/RepoMoney.cpp Repo/RepoMoney.h Repo/RepoInFileMoney.cpp Repo/RepoInFileMoney.h Repo/IRepoMoney.h Exception/Exception.h TicketValidator/TicketValidator.cpp TicketValidator/TicketValidator.h MoneyValidator/MoneyValidator.cpp MoneyValidator/MoneyValidator.h)
