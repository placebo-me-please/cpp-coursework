#include "Account.h"
#include "Trust_Account.h"

#include <string>
#include <iostream>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance}, int_rate {int_rate}, withdraw_count {0} {
    std::cout << "Trust Account Constructor Called" << std::endl;
}

bool Trust_Account::deposit(double amount){
    if (amount >= bonus_threshold){
        amount += bonus_amount;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if (amount <= balance * withdraw_threshold){
        return Account::withdraw(amount);
    }
    return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}