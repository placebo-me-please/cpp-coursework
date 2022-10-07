#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

//method signatures
//NOTE: after the code is functional, implement const correctness to protect the text file
void print_match_count(std::ifstream &read_file, std::string &search_word);
bool text_match(std::string &search_word, std::string &file_word);

int main() {
    
    //open the file and verify it did so correctly
    std::ifstream in_file {"romeo-and-juliet.txt"};
    if (!in_file){
        std::cerr << "The file did not open correctly - please try again" << std::endl;
        return 1;
    }
    
    //ask user for input
    std::string search_word {""};
    
    //call the display_match_count() method
    print_match_count(in_file, search_word);
    
    //close the file and terminate main()
    in_file.close();
    return 0;
}

//method implementations
void print_match_count(std::ifstream &read_file, std::string &search_word) {
    
    std::cout << "Testing print_match_count() call" << std::endl;
    
    int match_count {0};
    std::string file_word {""};
    
    //enter control flow
        
        //obtain the word from the text file
        
        //call the text_match() method - if the return value is true increment match_count
        if (text_match(search_word, file_word))
            match_count += 1;
        
    //display the search result to the user
    std::cout << "Your search word has " << match_count << " hits" << std::endl;
}

bool text_match(std::string &search_word, std::string &file_word) {
    
    std::cout << "Testing text_match() call" << std::endl;
    
    return false;
}