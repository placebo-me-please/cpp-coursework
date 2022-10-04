// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

int main() {
    std::cout.precision(2);
    std::cout << std::fixed;
    
//Application Testing
//-----------------------------------------------------------------

    //Exception Testing
    //-----------------------------------------------------------------
    
    //negative balance initialization
    //-------------------------------
    try {
        Account * negative_account_bal = new Savings_Account {"Scooby", -1, 1.0};
    }
    catch (const NegativeBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    //overdraft
    //-------------------------------
    Account * overdraft_account_bal = new Savings_Account {"Shaggy", 1000, 1.0};
    std::vector <Account *> overdraft_vector;
    overdraft_vector.push_back(overdraft_account_bal);
    try {
        withdraw(overdraft_vector, 1001.00);
    }
    catch (const OverdraftException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
//    //Savings Accounts
//    //-----------------------------------------------------------------
//    Account * sa1 = new Savings_Account {};
//    Account * sa2 = new Savings_Account {"Superman"};
//    Account * sa3 = new Savings_Account {"Batman", 2000};
//    Account * sa4 = new Savings_Account {"Wonderwoman", 5000, 5.0};
//    
//    std::vector <Account *> savings_accounts;
//    savings_accounts.push_back(sa1);
//    savings_accounts.push_back(sa2);
//    savings_accounts.push_back(sa3);
//    savings_accounts.push_back(sa4);
//    
//    deposit(savings_accounts, 1000.00);
//    withdraw(savings_accounts,2000.00);
//    display(savings_accounts);
//    
//    for (auto acct_ptr : savings_accounts)
//        delete acct_ptr;
//    
//    // Checking Accounts
//    //-----------------------------------------------------------------
//    Account * ca1 = new Checking_Account {};
//    Account * ca2 = new Checking_Account {"Inky"};
//    Account * ca3 = new Checking_Account {"Pinky", 1000};
//    Account * ca4 = new Checking_Account {"Winky", 2000, 1.00};
//    
//    std::vector <Account *> checking_accounts;
//    checking_accounts.push_back(ca1);
//    checking_accounts.push_back(ca2);
//    checking_accounts.push_back(ca3);
//    checking_accounts.push_back(ca4);
//
//    deposit(checking_accounts, 100);
//    withdraw(checking_accounts, 1100);
//    display(checking_accounts);
//    
//    for (auto acct_ptr : checking_accounts)
//        delete acct_ptr;
// 
//    // Trust Accounts
//    //-----------------------------------------------------------------
//    Account * ta1 = new Trust_Account {};
//    Account * ta2 = new Trust_Account {"Grumpy"};
//    Account * ta3 = new Trust_Account {"Sleepy", 2000};
//    Account * ta4 = new Trust_Account {"Mopey", 4000, 5};
//    
//    std::vector <Account *> trust_accounts;
//    trust_accounts.push_back(ta1);
//    trust_accounts.push_back(ta2);
//    trust_accounts.push_back(ta3);
//    trust_accounts.push_back(ta4);
//    
//    deposit(trust_accounts, 200);
//    deposit(trust_accounts, 2000);
//    withdraw(trust_accounts, 473);
//    withdraw(trust_accounts, 100);
//    withdraw(trust_accounts, 100);
//    withdraw(trust_accounts, 100);
    
    return 0;
}

