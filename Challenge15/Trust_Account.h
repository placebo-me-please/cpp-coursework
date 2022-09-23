#ifndef TRUST_ACCOUNT_H
#define TRUST_ACCOUNT_H

#include "Savings_Account.h"

#include <string>
#include <iostream>

class Trust_Account : public Savings_Account {
    //operator overloader is semi-specific to this derived class
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);

private:
//default values for no-arg constructors
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.02;
    
//values used to control deposit / withdraw rules
//  static constexpr double bonus_threshold = 2000.0;
//  static constexpr double bonus_amount = 50.0;
//  static constexpr double withdraw_limit = 0.20;
//  static int withdraw_count = 0;

protected:
//variables unique to this derived class
    double int_rate;

public:
//default constructor signature
//first two attributes passed to BASE class constructor; final attribute passed to DERIVED class constructor
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);

};



#endif // TRUST_ACCOUNT_H
