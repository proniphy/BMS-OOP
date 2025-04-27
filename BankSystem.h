#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "BankAccount.h"

class BankSystem
{
private:
    vector<BankAccount> accounts;

    void saveAccountsToFile() const;
    void loadAccountsFromFile();

public:
    BankSystem();

    void createAccount(int accNum, const string& holder, const string& type);
    void createAccount();
    BankAccount* findAccountByNumber(int accNum) const;
    void displayAccountInfo(int accNum) const;

	void withdrawFromAccount(int accNum, double amount) const;

	void depositToAccount(int accNum, double amount) const;

	// Function to delete an account
	void deleteAccount(int accNum);

    void displayAllAccounts() const;
};