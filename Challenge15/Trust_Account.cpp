#include "Account.h"
#include "Trust_Account.h"

#include <string>
#include <iostream>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, int_rate {int_rate}, withdraw_count {0} {
    std::cout << "Trust Account Constructor Called" << std::endl;
}

bool Trust_Account::deposit(double amount){
    if (amount >= bonus_threshold){
        amount += bonus_amount;
    }
    return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount){
    if (amount <= balance * withdraw_threshold && withdraw_count < 3){
        withdraw_count += 1;
        return Account::withdraw(amount);
    }
    
    if (withdraw_count == 3)
        std::cout << "Warning: Withdraw limit of Trust Account Reached!" << std::endl;
    
    if (amount > balance * withdraw_threshold)
        std::cout << "Warning: Cannot withdraw more than " << 100 * int_rate << "% of your account balance" << std::endl;
    
    return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust Account: " << account.name << ": $" << account.balance << ", " << 100 * account.int_rate << "%, transaction count: " << account.withdraw_count <<"]";
    return os;
}