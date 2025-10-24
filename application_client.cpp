#include "Bank.h"
#include <iostream>
extern "C" {
    Bank* Bank_new() { return new Bank(); }
    void Bank_loadClients(Bank* b, const char* filename) { b->loadClients(filename); }
    void Bank_addClient(Bank* b, int id, const char* name, double balance) { b->addClient(id, name, balance); }
    void Bank_deposit(Bank* b, int id, double amount) { b->deposit(id, amount); }
    void Bank_withdraw(Bank* b, int id, double amount) { b->withdraw(id, amount); }
    double Bank_getBalance(Bank* b, int id) { return b->getBalance(id); }
}
