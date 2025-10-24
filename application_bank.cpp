// application_bank.cpp
#include "bank.h"
#include <iostream>
#include <iomanip>

int Bank::findClientIndex(const std::string& account_number) const {
    for (size_t i = 0; i < clients.size(); ++i) {
        if (clients[i].account_number == account_number)
            return static_cast<int>(i);
    }
    return -1; // not found
}

void Bank::addClient(const std::string& name, const std::string& ssn,
                     const std::string& account_number, double balance) {
    if (findClientIndex(account_number) != -1) {
        std::cout << "❌ Account already exists.\n";
        return;
    }
    clients.push_back({name, ssn, account_number, balance});
    std::cout << "✅ Client added successfully.\n";
}

void Bank::deposit(const std::string& account_number, double amount) {
    int index = findClientIndex(account_number);
    if (index == -1) {
        std::cout << "❌ Account not found.\n";
        return;
    }
    if (amount <= 0) {
        std::cout << "❌ Invalid deposit amount.\n";
        return;
    }
    clients[index].balance += amount;
    std::cout << "✅ Deposit successful. New balance: $" << clients[index].balance << "\n";
}

void Bank::withdraw(const std::string& account_number, double amount) {
    int index = findClientIndex(account_number);
    if (index == -1) {
        std::cout << "❌ Account not found.\n";
        return;
    }
    if (amount <= 0) {
        std::cout << "❌ Invalid withdrawal amount.\n";
        return;
    }
    if (clients[index].balance < amount) {
        std::cout << "❌ Insufficient funds.\n";
        return;
    }
    clients[index].balance -= amount;
    std::cout << "✅ Withdrawal successful. New balance: $" << clients[index].balance << "\n";
}

void Bank::displayClient(const std::string& account_number) const {
    int index = findClientIndex(account_number);
    if (index == -1) {
        std::cout << "❌ Account not found.\n";
        return;
    }

    const Client& c = clients[index];
    std::cout << "\nClient Info:\n";
    std::cout << "Name: " << c.name << "\n"
              << "SSN: " << c.ssn << "\n"
              << "Account #: " << c.account_number << "\n"
              << std::fixed << std::setprecision(2)
              << "Balance: $" << c.balance << "\n\n";
}

void Bank::displayAllClients() const {
    std::cout << "\n=== All Clients ===\n";
    for (const auto& c : clients) {
        std::cout << c.name << " | " << c.account_number
                  << " | $" << std::fixed << std::setprecision(2)
                  << c.balance << "\n";
    }
    std::cout << "===================\n";
}

