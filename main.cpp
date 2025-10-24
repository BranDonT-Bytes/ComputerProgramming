#include "Bank.h"
#include <iostream>
#include <string>

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
        std::cout << "6. Load Clients from File\n";
        std::cout << "7. Save Clients to File\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: // Add new client
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

            case 2: // Deposit
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                balance = bank.deposit(acc, amount);
                std::cout << "Updated balance: " << balance << "\n";
                break;

            case 3: // Withdraw
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                balance = bank.withdraw(acc, amount);
                std::cout << "Updated balance: " << balance << "\n";
                break;

            case 4: // Display single client info
                std::cout << "Enter Account #: ";
                std::cin >> acc;
                bank.displayClient(acc);
                break;

            case 5: // Display all clients
                bank.displayAllClients();
                break;

            case 6: // Load clients from file
            {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                bank.load_clients_info(filename);
                break;
            }

            case 7: // Save clients to file
            {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                bank.saving_info(filename);
                break;
            }

            case 0:
                std::cout << "Exiting...\n";
                break;

            default:
                std::cout << "Invalid option.\n";
        }
    } while (choice != 0);

    return 0;
}

