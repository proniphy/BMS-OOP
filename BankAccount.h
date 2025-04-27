#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Transaction.h"

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolder;
    double balance;
    string accountType;
    vector<Transaction> transactions;

public:
    BankAccount(int accNum, const string& holder, const string& type);

    void deposit(double amount);

    void withdraw(double amount);

    void displayAccountInfo() const;

    int getAccountNumber() const;
};