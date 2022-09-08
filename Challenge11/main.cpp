#include <iostream>
#include <vector>

//FUNCTION PROTOTYPES
//----------------------------------------------------------------------------------------
int user_input_validation(int range_low, int range_high);
int statistics_menu();
int print_vector(const std::vector <int> &user_vector);
int add_element(std::vector <int> &user_vector);
int print_mean(const std::vector <int> &user_vector);
int print_range(const std::vector <int> &user_vector);

//GLOBAL CONSTANTS
//----------------------------------------------------------------------------------------
const int range_low {1};
const int range_high {10};

//MAIN PROGRAM
//----------------------------------------------------------------------------------------
int main() {

    std::cout << "Modular Statistics Program" << std::endl;
    
    //user data entry & validation
    //BUG: the program terminates if whitespace is entered - need to learn error handling to resolve the issue methinks!
    std::cout << "Begin by entering five integers between " << range_low << " - " << range_high << std::endl;
    int user_entry {};
    std::vector <int> number_vector (5,0);
    
    //validation loop
    for (int i {0}; i < 5; i++) {
        std::cout << "Enter element " << i << ": ";
        user_entry = user_input_validation(range_low, range_high);
        number_vector.at(i) = user_entry;
    }
    
    //statistics loop
    //the menu will prompt the user for an entry until they quit the program
    int menu_selection {};
    bool statistics_loop {true};
    while (statistics_loop){
        
        menu_selection = statistics_menu();
        
        switch (menu_selection){
            case 1:{
                print_vector(number_vector);
                break;
            }
            case 2:{
                add_element(number_vector);
                break;
            }
            case 3:{
                print_mean(number_vector);
                break;
            }
            case 4:{
               print_range(number_vector);
               break;
            }
            case 5:{
                statistics_loop = false;
                std::cout << "\nThanks for using the program - see you next time!" <<std::endl;
                break;
            }
        }
    }
    
    return 0;

}

//PROGRAM FUNCTIONS
//----------------------------------------------------------------------------------------
int user_input_validation(int range_low, int range_high){
    
    //this function receives the low and high bounds of the integer range
    //it returns a validated value to main() OR loops until the user selects a valid value
    bool entry_validation {false};
    std::string user_entry_string {};
    int user_entry {};
    
    while (!entry_validation){
        
        //BUG: the program terminates if whitespace is entered - need to learn error handling to resolve the issue methinks!
        std::getline(std::cin, user_entry_string);
        user_entry = std::stoi(user_entry_string);
        
        //write the valid entry to the vector
        if (user_entry >= range_low && user_entry <= range_high){
            return user_entry;
        }
        
        //reject the invalid entry and ask again
        //cin.ignore() prevents a race condition when a character is entered! something to do with how cin reads the buffer
        else {
            std::cin.clear();
            std::cin.ignore(1000,'\n');      
            std::cout << "Sorry, that entry is not valid. Try again: ";
        }
    }
    
    return 0;

}

int statistics_menu () {
    
    //this function receives no input
    //it displays the menu and returns a validated value that will be used to select a statistics module

    //menu console
    std::cout << "\nSelect one of the following menu options" << std::endl;
    std::cout << "1 - Print numbers" << std::endl;
    std::cout << "2 - Add a number" << std::endl;
    std::cout << "3 - Display mean of the numbers" << std::endl;
    std::cout << "4 - Display the range of the numbers" << std::endl;
    std::cout << "5 - Quit" << std::endl;
    std::cout << "\nInput your selection: ";
    
    //validation
    int user_entry {};
    user_entry = user_input_validation(1, 5); 
    
    return user_entry;
    
}

int print_vector(const std::vector <int> &user_vector) {

    std::cout << "\nHere are the contents of the vector: \n";
    std::cout << "[ ";
    for(auto vector_element : user_vector) {
        std::cout << vector_element << " ";
    }
    std::cout << "]\n";

    return 0;

}

int add_element(std::vector <int> &user_vector) {
    
    std::cout << "\nEnter an integer between " << range_low << " - " << range_high << ": ";
    int user_entry {};
    user_entry = user_input_validation(range_low, range_high);
    user_vector.push_back(user_entry);
    
    return 0;
    
}

int print_mean(const std::vector <int> &user_vector) {
    
    double vector_mean {};
    for(auto vector_element : user_vector) {
        vector_mean += (double)vector_element;
    }
    vector_mean = vector_mean / user_vector.size();
    
    std::cout.precision(3);
    std::cout << "\nThe mean value of the elements is: " << vector_mean << std::endl;
    
    return 0;
    
}

int print_range(const std::vector <int> &user_vector) {
    
    //setting min_num equal to range_high + 1 means that the first number assessed cannot possibly be higher
    //similar logic is applied to the max_number variable
    int min_num {range_high + 1};
    int max_num {range_low - 1};
    
    for (auto vector_element : user_vector) {
        if (vector_element < min_num){
            min_num = vector_element;
        }
        else if (vector_element > max_num) {
            max_num = vector_element;
        }
        else
            continue;
    }
    
    std::cout << "\nThe range of elements is [" << min_num << ", " << max_num << "]" << std::endl;
    
    return 0;
    
}