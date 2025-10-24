#pragma once
#include <string>
#include <unordered_map>

// Represents a single bank client
struct Client {
    int id;                         // Unique identifier for the client
    std::string name;               // Stores the name of the client
    std::string ssn;                // Stores the Social Security Number (SSN) of the client
    std::string bank_account_number; // Stores the bank account number of the client
    double balance;                 // Stores the current balance in the client's account
};

// Represents a bank system that manages multiple clients
class Bank {
private:
    std::unordered_map<int, Client> clients;  // Stores clients by ID

public:
    // --- File Operations ---
    void loadClients(const std::string& filename);

    // --- Client Management ---
    void addClient(int id, const std::string& name, const std::string& ssn,
                   const std::string& bank_account_number, double balance);

    // --- Transactions ---
    void deposit(int id, double amount);
    void withdraw(int id, double amount);

    // --- Information Retrieval ---
    double getBalance(int id) const;
    std::string getClientInfo(int id) const;

    // --- Utility ---
    bool clientExists(int id) const;
};
