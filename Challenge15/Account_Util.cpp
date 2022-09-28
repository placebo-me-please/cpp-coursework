#include <iostream>
#include "Account_Util.h"

// Helper functions for Account and its derived classes
// -----------------------------------------------------------------------------------------------

// Deposits supplied amount to each Account object in the vector
void deposit(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Depositing to Accounts =================================" << std::endl;
    for (auto &acc : accounts)  {
        if (acc->deposit(amount)) 
            std::cout << "Deposited " << amount << " to " << *acc << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *acc << std::endl;
    }
}

// Withdraw amount from each Account object in the vector
void withdraw(std::vector<Account *> &accounts, double amount) {
    std::cout << "\n=== Withdrawing from Accounts ==============================" <<std::endl;
    for (auto &acc : accounts)  {
        if (acc->withdraw(amount)) 
            std::cout << "Withdrew " << amount << " from " << *acc << std::endl;
        else
            std::cout << "Failed Withdrawal of " << amount << " from " << *acc << std::endl;
    } 
}

// Display each account using an overloaded << operator
void display(std::vector<Account *> &accounts) {
    std::cout << "\n=== Displaying Accounts ==============================" <<std::endl;
    for (auto &acc : accounts)
        std::cout << *acc << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    account.display();
    return os;
}