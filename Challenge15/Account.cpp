#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

/*virtual*/ bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

/*virtual*/ bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

Account::~Account() {};

/*virtual*/ void Account::display() const {};
