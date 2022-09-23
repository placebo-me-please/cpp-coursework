#include "Checking_Account.h"

#include <string>
#include <iostream>

Checking_Account::Checking_Account(std::string name, double balance, double withdraw_cost)
    //delegate "name" and "balance" to BASE class; then initialize DERIVED class attribute "penalty"
    : Account {name, balance}, withdraw_cost {1.50} {
    std::cout << "Checking Account Constructor Called" << std::endl;
}

bool Checking_Account::withdraw(double amount) {
    //invoke the BASE class method "withdraw" using scope resolution
    balance -= withdraw_cost;
    return Account::withdraw(amount);
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account) {
    os << "[Checking Account: " << account.name << ": " << account.balance << ", $" << account.withdraw_cost << " Withdraw Cost]";
    return os;
}
