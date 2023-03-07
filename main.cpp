#include "Tests/tests.h"
#include "UI/UI.h"

using namespace std;

int main() {
    testAll();
    RepoInFile repoInFile(R"(/Users/bogdanzarnescu/Desktop/An1/Facultate-OOP/Lab-10-live/tickets.txt)");
    RepoInFileMoney repoInFileMoney(R"(/Users/bogdanzarnescu/Desktop/An1/Facultate-OOP/Lab-10-live/money.txt)");
    TicketValidator ticketValidator(repoInFile);
    MoneyValidator moneyValidator(repoInFileMoney);
    Service service(repoInFile, repoInFileMoney, ticketValidator, moneyValidator);
    UI ui(service);
    ui.runMenu();
    return 0;
}
