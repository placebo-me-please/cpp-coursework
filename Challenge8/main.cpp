#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //change machine
    //this code takes a user user input of dollars
    //it then outputs what change should be given in denominations of DECREASING size
    
    //user input
    cout << "Enter the amount of cents you want to calculate the change for: ";
    int user_money {0};
    cin >> user_money;
    cout << "You entered " << user_money << " cents" << endl;
    
    //change calculation
    //note that the modulo operator is not defined for vars of type "double"
    vector <int> change_vector {};
    
    //dollars
    change_vector.push_back(user_money / 100);
    
    //coinage
    //if there is a remainder then the coinage must be determined
    //demoniations decrease in size until the modulo result is ZERO
    //this exercised in subsequent control flows
    
    int change_remainder {0};
    
    //REFACTOR NOTE: could very easily combine these control flows into a single, more compact control flow
    //quarters
    if (user_money % 100 != 0) {
        change_remainder = user_money % 100;
        change_vector.push_back(change_remainder / 25);
    }
    else if (user_money % 100 == 0) {
        change_vector.push_back(0);
    }

    //dimes
    if (change_remainder % 25 != 0) {
        change_remainder %= 25;
        change_vector.push_back(change_remainder / 10);
    }
    else if (user_money % 25 == 0) {
        change_vector.push_back(0);
    }    
    
    //nickles
    if (change_remainder % 10 != 0) {
        change_remainder %= 10;
        change_vector.push_back(change_remainder / 5);
    }
    else if (user_money % 10 == 0) {
        change_vector.push_back(0);
    } 
    
    //pennies
    if (change_remainder % 5 != 0) {
        change_remainder %= 5;
        change_vector.push_back(change_remainder);
    }
    else if (user_money % 5 == 0) {
        change_vector.push_back(0);
    } 
    
    //user output
    cout << "Here is your change: \n";
    cout << "Dollars:   " << change_vector.at(0);
    cout << "\nQuarters:  " << change_vector.at(1);
    cout << "\nDimes:     " << change_vector.at(2);
    cout << "\nNickles:   " << change_vector.at(3);
    cout << "\nPennies:   " << change_vector.at(4) << endl;
    
    return 0;
}
