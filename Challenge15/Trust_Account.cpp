#include "Trust_Account.h"

#include <string>
#include <iostream>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance}, int_rate {int_rate} {
    std::cout << "Trust Account Constructor Called" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}