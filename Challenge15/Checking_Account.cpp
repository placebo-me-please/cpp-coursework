#include "Checking_Account.h"

#include <string>
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance, double withdraw_cost)
<<<<<<< HEAD
    //delegate "name" and "balance" to BASE class; then initialize DERIVED class attribute "penalty"
    : Account {name, balance}, withdraw_cost {withdraw_cost} {
=======
    //delegate "name" and "balance" to BASE class; then initialize DERIVED class attribute "withdraw_cost"
    : Account {name, balance}, withdraw_cost {1.50} {
>>>>>>> developement
}

/*virtual*/ bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

<<<<<<< HEAD
std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": $" << account.balance << ", $" << account.withdraw_cost << " Withdraw Cost]";
    return os;
=======
/*virtual*/ bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + withdraw_cost);
>>>>>>> developement
}

/*virtual*/ void Checking_Account::display() const {
    std::cout << "[Checking Account of " << name << ": $" << balance << ", Withdraw Cost: $" << withdraw_cost << "]";
}