#pragma once

#include <string>
#include <chrono>

#include "Transaction.h"

using namespace std;

Transaction::Transaction(Type t, double amt) : type(t), amount(amt)  
{  
    // Get current time as string using chrono  
    auto now = chrono::system_clock::now();
    time_t now_c = chrono::system_clock::to_time_t(now);
    struct tm timeInfo;
    localtime_s(&timeInfo, &now_c); // Thread-safe alternative to localtime  

    ostringstream oss;
    oss << put_time(&timeInfo, "%Y-%m-%d %H:%M:%S");
    timestamp = oss.str();
}

void Transaction::display() const
{
    cout << (type == Type::Deposit ? "Deposit" : "Withdrawal")  
             << " of $" << amount << " on " << timestamp << "\n";
}