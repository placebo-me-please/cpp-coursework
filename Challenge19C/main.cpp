#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

//method signatures
//NOTE: after the code is functional, implement const correctness to protect the text file
void print_match_count(std::ifstream &read_file);
bool text_match(std::string &search_word, std::string &file_word);

int main() {
    
    //open the text file
    std::ifstream in_file {"romeo-and-juliet.txt"};
    
    //verify that the file opened correctly
    if (!in_file){
        std::cerr << "The file did not open correctly - please try again" << std::endl;
        return 1;
    }
    
    //call the display_match_count() method
    print_match_count(in_file);
    
    //close the file
    in_file.close();
    
    
    return 0;
    
}

//method implementations
void print_match_count(std::ifstream &read_file) {
    
    std::cout << "Testing print_match_count() call" << std::endl;
    
}

bool text_match(std::string &search_word, std::string &file_word) {
    
    std::cout << "Testing text_match() call" << std::endl;
    
}