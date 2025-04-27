#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "BankSystem.h"
#include "BankAccount.h"

using namespace std;

BankSystem::BankSystem()
{
    this->loadAccountsFromFile();
}

void BankSystem::saveAccountsToFile() const
{
    ofstream outFile("accounts.txt");
    for (const BankAccount& acc : this->accounts)
    {
        outFile << acc.getAccountNumber() << "\n";
    }
}

void BankSystem::loadAccountsFromFile()
{
    ifstream inFile("accounts.txt");
    int accNum;
    while (inFile >> accNum)
    {
        this->accounts.emplace_back(accNum, "Holder", "Savings");
    }
}
void BankSystem::createAccount()
{
	int accNum;
	string holder, type;
	cout << "Enter account number: ";
	cin >> accNum;
	cout << "Enter account holder name: ";
	cin >> holder;
	cout << "Enter account type (Savings/Checking): ";
	cin >> type;
	this->createAccount(accNum, holder, type);
}

void BankSystem::createAccount(int accNum, const string& holder, const string& type)
{
    this->accounts.emplace_back(accNum, holder, type);
    this->saveAccountsToFile();
}

BankAccount* BankSystem::findAccountByNumber(int accNum) const
{
   for (const BankAccount& acc : this->accounts)
   {
       if (acc.getAccountNumber() == accNum)
       {
           return const_cast<BankAccount*>(&acc);
       }
   }
   return nullptr;  
}

void BankSystem::displayAccountInfo(int accNum) const
{
	const BankAccount* acc = this->findAccountByNumber(accNum);
	if (acc)
    {
		acc->displayAccountInfo();
	}
	else
    {
		cout << "Account not found.\n";
	}
}


void BankSystem::withdrawFromAccount(int accNum, double amount) const
{
	BankAccount* acc = this->findAccountByNumber(accNum);
	if (acc)
    {
		acc->withdraw(amount);
		this->saveAccountsToFile();
	}
	else
    {
		cout << "Account not found.\n";
	}
}

void BankSystem::depositToAccount(int accNum, double amount) const
{
    BankAccount* acc = this->findAccountByNumber(accNum);
    if (acc)
    {
        acc->deposit(amount);
        this->saveAccountsToFile();
    }
    else
    {
        cout << "Account not found.\n";
    }
}

void BankSystem::deleteAccount(int accNum)
{
    auto it = remove_if(this->accounts.begin(), this->accounts.end(),
        [accNum](const BankAccount& acc) { return acc.getAccountNumber() == accNum; });
    if (it != this->accounts.end())
    {
        accounts.erase(it, accounts.end());
        this->saveAccountsToFile();
    }
    else
    {
        cout << "Account not found.\n";
    }
}

void BankSystem::displayAllAccounts() const
{
    for (const BankAccount& acc : this->accounts)
    {
        acc.displayAccountInfo();
    }
}