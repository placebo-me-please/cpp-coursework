#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    : Account {name, balance}, int_rate{int_rate} {
}

/*virtual*/ bool Savings_Account::deposit(double amount) /*override*/ {
    
    //savings accounts earn interest on deposits 
    amount += amount * (int_rate/100);
    return Account::deposit(amount);
}

<<<<<<< HEAD
std::ostream &operator<<(std::ostream &os, const Savings_Account &account) {
    os << "[Savings_Account: " << account.name << ": $" << account.balance << ", " << account.int_rate << "%]";
    return os;
=======
/*virtual*/ bool Savings_Account::withdraw(double amount) /*override*/ {
    return Account::withdraw(amount);
}

/*virtual*/ void Savings_Account::display() const {
    std::cout << "[Savings Account of " << name << ": $" << balance << ", Interest Rate: " << int_rate << "%]";
>>>>>>> developement
}

