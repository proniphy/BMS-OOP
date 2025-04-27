#include <iostream>
#include <string>

#include "BankSystem.h"
#include "UserAuth.h"

using namespace std;

int main()
{
    BankSystem bankSystem;
    string username, password;
    int choice;

    cout << "Welcome to the Bank System\n";
    cout << "1. Login\n2. Register\nChoose an option: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        if (UserAuth::login(username, password))
        {
            cout << "Login successful!\n";
            
            int accNum;
            double amount;

            do
            {
                cout << "\n=== Bank Menu ===\n";
                cout << "1. Create new account\n";
                cout << "2. Deposit money\n";
                cout << "3. Withdraw money\n";
                cout << "4. View account info\n";
                cout << "5. View all accounts\n";
                cout << "6. Delete an account\n";
                cout << "7. Exit\n";
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice)
                {
                    case 1:
                        bankSystem.createAccount();
                        break;
                    case 2:
                        cout << "Enter account number: ";
                        cin >> accNum;
                        cout << "Enter amount to deposit: ";
                        cin >> amount;
                        bankSystem.depositToAccount(accNum, amount);
                        break;
                    case 3:
                        cout << "Enter account number: ";
                        cin >> accNum;
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        bankSystem.withdrawFromAccount(accNum, amount);
                        break;
                    case 4:
                        cout << "Enter account number: ";
                        cin >> accNum;
                        bankSystem.displayAccountInfo(accNum);
                        break;
                    case 5:
                        bankSystem.displayAllAccounts();
                        break;
                    case 6:
                        cout << "Enter account number to delete: ";
                        cin >> accNum;
                        bankSystem.deleteAccount(accNum);
                        break;
                    case 7:
                        cout << "Exiting. Goodbye!\n";
                        break;
                    default:
                        cout << "Invalid option. Try again.\n";
                }
            }
            while (choice != 7);
        }
        else
        {
            cout << "Invalid credentials.\n";
        }
    }
    else if (choice == 2)
    {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        UserAuth::registerUser(username, password);
        cout << "Registration successful!\n";
    }

    return 0;
}