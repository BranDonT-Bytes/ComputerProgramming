#include "Bank.h"
#include <iostream>

extern "C" {

    // --- Bank Constructor ---
    Bank* Bank_new() {
        return new Bank();
    }

    // --- File Operations ---
    void Bank_loadClients(Bank* b, const char* filename) {
        b->loadClients(filename);
    }

    // --- Client Management ---
    void Bank_addClient(Bank* b, int id, const char* name, const char* ssn,
                        const char* bank_account_number, double balance) {
        b->addClient(id, name, ssn, bank_account_number, balance);
    }

    // --- Transactions ---
    void Bank_deposit(Bank* b, int id, double amount) {
        b->deposit(id, amount);
    }

    void Bank_withdraw(Bank* b, int id, double amount) {
        b->withdraw(id, amount);
    }

    // --- Information Retrieval ---
    double Bank_getBalance(Bank* b, int id) {
        return b->getBalance(id);
    }

    // --- Client Data Variables ---

    // Stores the number of clients in the bank
    int num_client;

    // Pointer to a dynamic array of Client objects
    Client* clients;
}
