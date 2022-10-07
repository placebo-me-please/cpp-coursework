#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

//KNOWN ISSUES
    //code is case sensitive
    //if any punctuation immediately follows a word the search word will not match

//method signatures
void print_match_count(std::ifstream &read_file, std::string &search_word);
bool text_match(std::string &search_word, std::string &file_word);

int main() {
    
    //open the file and verify it did so correctly
    std::ifstream in_file;
    in_file.open("validation-text.txt");
    if (!in_file){
        std::cerr << "The file did not open correctly - please try again" << std::endl;
        return 1;
    }
    
    //ask user for their search word
    std::string search_word {""};
    std::cout << "Enter a word to search for in Romeo & Juliet: ";
    std::cin >> search_word;
    
    //call the display_match_count() method
    print_match_count(in_file, search_word);
    
    //close the file and terminate main()
    in_file.close();
    return 0;
}

//method implementations
void print_match_count(std::ifstream &read_file, std::string &search_word) {
    
    //enter control flow
    std::string file_word {""};
    int match_count {0};
    int search_count {0};
    while (read_file >> file_word) {
        
        //call the text_match() method - if the return value is true increment match_count
        if (file_word == search_word)
            match_count += 1;
        
        search_count += 1;
    }
        
    //display the search result to the user
    std::cout << search_count << " words were searched in the file" << std::endl;
    std::cout << "Your search word has " << match_count << " hits" << std::endl;
}

bool text_match(std::string &search_word, std::string &file_word) {
    
    return false;
}