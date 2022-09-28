//#ifndef CHECKING_ACCOUNT_H
//#define CHECKING_ACCOUNT_H
//
//#include "Account.h"
//
//#include <string>
//#include <iostream>
//
//class Checking_Account : public Account {
//private:
//    //default values for no-arg constructors
//    static constexpr const char *def_name = "Unnamed Checking Account";
//    static constexpr double def_balance = 0.0;
//    static constexpr double def_withdraw_cost = 1.50;
//
//protected:
//    //variables unique to this derived class
//    double withdraw_cost;
//    
//public:
//    //default constructor signature
//    //first two attributes passed to BASE class constructor; final attribute passed to DERIVED class constructor
//    Checking_Account(std::string name = def_name, double balance = def_balance, double withdraw_cost = def_withdraw_cost);
//    
//    //withdraw method signature
//    bool withdraw(double amount);
//    
//    //deposit method signature not required - this class will inherit deposit method from BASE class
//};
//
//#endif // CHECKING_ACCOUNT_H
