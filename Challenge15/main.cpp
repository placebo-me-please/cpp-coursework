// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
//    // Accounts
//    vector<Account> accounts;
//    accounts.push_back(Account {});
//    accounts.push_back(Account {"Larry"});
//    accounts.push_back(Account {"Moe", 2000} );
//    accounts.push_back(Account {"Curly", 5000} );
//    
//    display(accounts);
//    deposit(accounts, 1000);
//    withdraw(accounts,2000);
//    
    // Savings Accounts
//    vector<Savings_Account> sav_accounts;
//    sav_accounts.push_back(Savings_Account {} );
//    sav_accounts.push_back(Savings_Account {"Superman"} );
//    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
//    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );
//
//    display(sav_accounts);
//    deposit(sav_accounts, 1000);
//    withdraw(sav_accounts, 2000);
    
    // Checking Accounts
    vector <Checking_Account> checking_accounts;
    checking_accounts.push_back(Checking_Account {});
    checking_accounts.push_back(Checking_Account {"Inky"});
    checking_accounts.push_back(Checking_Account {"Pinky", 1000});
    checking_accounts.push_back(Checking_Account {"Blinky", 1100, 1.50});
    
    display(checking_accounts);
    deposit(checking_accounts, 100);
    withdraw(checking_accounts, 1100);
    
    // Trust Accounts
    vector <Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account {});
    
    display(trust_accounts);
    deposit(trust_accounts, 200);
    deposit(trust_accounts, 2000);
    withdraw(trust_accounts, 1801);
    withdraw(trust_accounts, 100);
    withdraw(trust_accounts, 100);
    withdraw(trust_accounts, 100);
    withdraw(trust_accounts, 100);
    
    return 0;
}

//You are provided with a completed Account class hierarchy that was completed in Section 1.
//The provided class hierarchy does not use dynamic polymorphism (it has no virtual functions!)
//
//Your challenge is the following:
//
//1.  Modify the Account class so that it is now an Abstract class by adding the following pure virtual functions:
//        virtual bool deposit(double amount) = 0;
//        virtual bool withdraw(double amount) = 0;
//
//        Hint: you can implement these functions in the Account class if it makes sense
//
//2. Create an I_Printable class interface as we did in the course and provide functionality so
//    all accounts are printable to an ostream using the overloaded insertion operator.
//    
//        class I_Printable
//        {
//            friend std::ostream &operator<<(std::ostream &os, const I_Printable &obj);
//        public:
//            virtual void print(std::ostream &os) const = 0;
//            virtual ~I_Printable() = default;
//        };
//
//3. Modify the functions in the Account_Util files so we only have one version of each. For example,
//
//        void display(const std::vector<Account *> &accounts);
//        void deposit(std::vector<Account *> &accounts, double amount);
//        void withdraw(std::vector<Account *> &accounts, double amount);
//        
//        Note that the vector is a vector of pointers to Account objects <Account *>
//        This is what we need for dynamic polymorphism.
//        
//4. Test your code with base class pointers as well as local objects.
//    I provided a simple main driver that will get you started
//
//Hints: 
//    - Reuse existing functionality!!
//    - If your class has a virtual function then be sure to implement a virtual destructor. 
//       You can have the C++ generate a default destructor for you with:
//           virtual ~Class_Name() = default;
//    - Take it one step at a time.
//    - Start by making the Account class abstract by adding the pure virtual functions.
