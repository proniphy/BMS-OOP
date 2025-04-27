#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "BankAccount.h"
#include "Transaction.h"

using namespace std;

BankAccount::BankAccount(int accNum, const string& holder, const string& type)
    : accountNumber(accNum), accountHolder(holder), balance(0.0), accountType(type) {}

void BankAccount::deposit(double amount)
{
    if (amount > 0)
    {
        this->balance += amount;
        this->transactions.emplace_back(Transaction::Type::Deposit, amount);
    }
}

void BankAccount::withdraw(double amount)
{
    if (amount > 0 && amount <= this->balance)
    {
        this->balance -= amount;
        this->transactions.emplace_back(Transaction::Type::Withdrawal, amount);
    }
}

void BankAccount::displayAccountInfo() const
{
    cout << "Account Number: " << this->accountNumber << "\n"
        << "Holder: " << this->accountHolder << "\n"
        << "Type: " << this->accountType << "\n"
        << "Balance: $" << this->balance << "\n";
    cout << "Transactions:\n";

    for (const auto& txn : this->transactions)
    {
        txn.display();
    }
}

int BankAccount::getAccountNumber() const
{
    return this->accountNumber;
}