#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << "Simple Statistics Program" << endl;
    
    //USER DATA ENTRY
    cout << "Begin by entering five integers between 1 - 10:" << endl;
    
    vector <int> num_vector (5,0);
    
    for (long unsigned int i {0} ; i < num_vector.size() ; ++i) {
        
        //validate the user entry 
        bool entry_validation {false};
        int user_entry {0};
        
        while (!entry_validation) {
            
            //user entry prompt
            //REFACTOR NOTE: think in terms of data streams (i.e. cin) rather than logical flow
            cout << "Enter element " << i << ": ";
            cin >> user_entry;
            
            //write the valid entry to the vector
            if (user_entry >= 1 && user_entry <= 10) {
                entry_validation = true;
                num_vector.at(i) = user_entry;
            }
            
            //reject the invalid entry and ask again
            //cin.ignore() prevents a race condition when a character is entered! something to do with how cin reads the buffer
            else {
                cin.clear();
                cin.ignore(1000,'\n');      
                cout << "Sorry, that entry is not valid. Try again: " << endl;
            }
        }
    }
    
    //STATISTICS MENU
    //enter a loop that displays the menu and prompts the user for their selection
    bool stats_loop {true};
    char user_select {};
    while (stats_loop) {
    
        //menu console
        cout << "\nSelect one of the following menu options" << endl;
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "R - Display the range of the numbers" << endl;
        cout << "Q - Quit" << endl;
        
        cout << "\nInput your selection: ";
        cin >> user_select;
            
        //switch-case control flow that manages valid menu selections
        //it serves the secondary purpose of being the data validator
        
        switch (user_select) {
            
            //print the contents of the vector
            case 'P' :
            case 'p' :
            {    
                cout << "\nHere are the numbers: " << endl;
                
                cout << "[ ";
                for (auto element_number : num_vector){
                    cout << element_number <<  " ";
                }
                cout << "]" << endl;
                
                break;
            }
            //append a number to the vector
            case 'A' :
            case 'a' :
            {    
                //user entry prompt
                cout << "\nEnter element " << num_vector.size() << ": ";
                int user_entry {};
                cin >> user_entry;
                
                //validate the user entry 
                //REFACTOR NOTE: this is the second instance of this code block, so consider consolidating it as a function
                bool entry_validation {false};
                while (!entry_validation) {
            
                    //write the valid entry to the vector
                    if (user_entry >= 1 && user_entry <= 10) {
                        entry_validation = true;
                        num_vector.push_back(user_entry);
                    }
            
                    //reject the invalid entry and ask again
                    else {
                        cout << "Sorry, that entry is not valid. Try again: ";
                        cin >> user_entry;
                    }
                }
                break;
            }    
            //display the mean value of the vector elements
            case 'M' :
            case 'm' :
            {
                int num_sum {};
                for (long unsigned int i {0} ; i < num_vector.size() ; ++i) {
                    num_sum += num_vector.at(i);
                }
                
                double element_avg {};
                element_avg = num_sum / num_vector.size();
                
                cout << "\nThe average value of the elements is: \n" << element_avg << endl;
                break;
            }   
            //display the largest and smallest elements (i.e. the range)
            case 'R' :
            case 'r' :
            {
                int max_num {};
                int min_num {};
                
                for (long unsigned int i {0} ; i < num_vector.size() ; ++i) {
                    if (i == 0) {
                        cout << num_vector.at(i);
                        max_num = num_vector.at(i);
                        min_num = num_vector.at(i);
                    }
                    
                    else if (i != 0) {
                        if (max_num < num_vector.at(i)){
                            max_num = num_vector.at(i);
                        }
                        
                        if (min_num > num_vector.at(i)){
                            min_num = num_vector.at(i);
                        }
                    }
                }
                cout << "\nThe range of elements is [" << min_num << ", " << max_num << "]\n";
                break;
            }
            
            //quit the application
            case 'Q' :
            case 'q' : 
            {
                stats_loop = false;
                break;
            }
            default : 
                cout << "\nSorry, that entry is not valid. Try again!\n";
        }
    }
}