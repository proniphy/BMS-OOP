#pragma once

#include <iostream>
#include <string>
#include <vector>

class Transaction
{
public:
    enum class Type { Deposit, Withdrawal };

private:
    Type type;
    double amount;
    std::string timestamp;

public:
    Transaction(Type t, double amt);

    void display() const;
};