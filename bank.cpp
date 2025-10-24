// Bank.cpp
#include "Bank.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

void Bank::loadClients(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) throw std::runtime_error("Unable to open file");

    clients.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Client c;
        ss >> c.id >> c.name >> c.balance;
        clients[c.id] = c;
    }
}

void Bank::addClient(int id, const std::string& name, double balance) {
    if (clients.count(id))
        throw std::runtime_error("Client already exists");
    clients[id] = {id, name, balance};
}

void Bank::deposit(int id, double amount) {
    if (!clients.count(id))
        throw std::runtime_error("Client not found");
    if (amount <= 0)
        throw std::runtime_error("Invalid deposit amount");
    clients[id].balance += amount;
}

void Bank::withdraw(int id, double amount) {
    if (!clients.count(id))
        throw std::runtime_error("Client not found");
    if (amount <= 0)
        throw std::runtime_error("Invalid withdrawal amount");
    if (clients[id].balance < amount)
        throw std::runtime_error("Insufficient funds");
    clients[id].balance -= amount;
}

double Bank::getBalance(int id) {
    if (!clients.count(id))
        throw std::runtime_error("Client not found");
    return clients[id].balance;
}

std::string Bank::getClientInfo(int id) {
    if (!clients.count(id))
        throw std::runtime_error("Client not found");
    const Client& c = clients.at(id);
    return "ID: " + std::to_string(c.id) + " | Name: " + c.name + " | Balance: " + std::to_string(c.balance);
}

