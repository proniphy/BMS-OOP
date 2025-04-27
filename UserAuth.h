#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class UserAuth
{
public:
    static bool login(const string_view& username, const string_view& password)
    {
        ifstream inFile("users.txt");
        string storedPass;
        string storedUser;
        while (inFile >> storedUser >> storedPass)
        {
            if (storedUser == username && storedPass == password)
            {
                return true;
            }
        }
        return false;
    }

    static void registerUser(const string& username, const string& password)
    {
        ofstream outFile("users.txt", ios::app);
        outFile << username << " " << password << "\n";
    }
};