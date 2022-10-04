#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

//Utility helper functions for Account class
//-----------------------------------------------------------------
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);
void display(std::vector<Account *> &accounts);

//Overloaded operator
//-----------------------------------------------------------------
std::ostream &operator<<(std::ostream &os, const Account &account);
#endif

//Exception Classes
//-----------------------------------------------------------------
class NegativeBalanceException : public std::exception {
public:
    NegativeBalanceException() noexcept = default;
    ~NegativeBalanceException() = default;
    virtual const char * what() const noexcept {
        return "Cannot create an account with a negative balance - please enter a starting balance that is greater than or equal to zero";
    }
};

class OverdraftException : public std::exception {
public:
    OverdraftException() noexcept = default;
    ~OverdraftException() = default;
    virtual const char * what() const noexcept {
        return "Cannot withdraw more money than is account - please enter a value less than or equal to account balance";
    }
};