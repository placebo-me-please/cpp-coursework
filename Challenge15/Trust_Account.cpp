#include "Account.h"
#include "Trust_Account.h"

#include <string>
#include <iostream>

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    : Savings_Account {name, balance, int_rate}, withdraw_count {0} {
    std::cout << "Trust Account Constructor Called" << std::endl;
}

/*virtual*/ bool Trust_Account::deposit(double amount){
    if (amount >= bonus_threshold){
        amount += bonus_amount;
    }
    return Savings_Account::deposit(amount);
}

/*virtual*/ bool Trust_Account::withdraw(double amount){
    if (amount <= balance * withdraw_threshold && withdraw_count < 3){
        withdraw_count += 1;
        return Account::withdraw(amount);
    }
    if (amount >= balance * withdraw_threshold)
        std::cout << "Withdraw request exceeds the limit - you may only withdraw up to " << withdraw_threshold*100 << "% of your balance" << std::endl;
    
    if (withdraw_count == 3)
        std::cout << "Number of withdraws exceeded - you may not withdraw more than three times per year" << std::endl;
    return false;
}

/*virtual*/ void Trust_Account::display() const {
    std::cout << "[Trust Account of " << name << ": $" << balance << ", Interest Rate: " << int_rate << "%, Withdraw Count: " << withdraw_count << "]";
}