#include "Checking_Account.h"

#include <string>
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance, double withdraw_cost)
    //delegate "name" and "balance" to BASE class; then initialize DERIVED class attribute "withdraw_cost"
    : Account {name, balance}, withdraw_cost {1.50} {
}

/*virtual*/ bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

/*virtual*/ bool Checking_Account::withdraw(double amount) {
    return Account::withdraw(amount + withdraw_cost);
}

/*virtual*/ void Checking_Account::display() const {
    std::cout << "[Checking Account of " << name << ": $" << balance << ", Withdraw Cost: $" << withdraw_cost << "]";
}