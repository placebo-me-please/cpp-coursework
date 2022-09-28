#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "Savings_Account.h"

#include <string>
#include <iostream>

class Trust_Account : public Savings_Account {
private:
    //default values for no-arg constructors
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 5.0;
    
    //values used to control deposit / withdraw rules
    static constexpr double bonus_threshold = 2000.0;
    static constexpr double bonus_amount = 50.0;
    static constexpr double withdraw_threshold = 0.20;

protected:
    //variables unique to this derived class
    double int_rate;
    int withdraw_count;

public:
    //default constructor signature
    //first two attributes passed to BASE class constructor; final attribute passed to DERIVED class constructor
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    
    //virtual method declarations
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void display() const override;
};
#endif // TRUST_ACCOUNT_H
