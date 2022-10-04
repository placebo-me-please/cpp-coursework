#include "Account.h"
#include "Account_Util.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
        if (balance < 0)
            throw NegativeBalanceException();
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
    }
    else
        throw OverdraftException();
}

Account::~Account() {};

/*virtual*/ void Account::display() const {};
