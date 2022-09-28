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

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}

Account::~Account() {
    std::cout << "Virtual Account Destructor Called" << std::endl;
}
