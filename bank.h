#pragma once
#include <string>
#include <unordered_map>

// Represents a single bank client
struct Client {
    int id;
    std::string name;
    double balance;
};

// Represents a bank system that manages multiple clients
class Bank {
private:
    std::unordered_map<int, Client> clients;  // stores clients by ID

public:
    // --- File Operations ---
    void loadClients(const std::string& filename);

    // --- Client Management ---
    void addClient(int id, const std::string& name, double balance);

    // --- Transactions ---
    void deposit(int id, double amount);
    void withdraw(int id, double amount);

    // --- Information Retrieval ---
    double getBalance(int id) const;
    std::string getClientInfo(int id) const;

    // --- Utility ---
    bool clientExists(int id) const;
};
