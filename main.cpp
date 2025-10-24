// main.cpp
#include "bank.h"
#include <iostream>

int main() {
    Bank bank;

    int choice;
    std::string name, ssn, acc;
    double amount, balance;

    do {
        std::cout << "\n===== Bank Menu =====\n";
        std::cout << "1. Add New Client\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Display Client Info\n";
        std::cout << "5. Display All Clients\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter name: ";
                std::cin >> name;
                std::cout << "Enter SSN: ";
                std::cin >> ssn;
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                std::cout << "Enter starting balance: ";
                std::cin >> balance;
                bank.addClient(name, ssn, acc, balance);
                break;

            case 2:
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                bank.deposit(acc, amount);
                break;

            case 3:
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                bank.withdraw(acc, amount);
                break;

            case 4:
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                bank.displayClient(acc);
                break;

            case 5:
                bank.displayAllClients();
                break;

            case 0:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}
