#include <iostream>
#include <string>

#include "Movie.h"

Movie::Movie(std::string title_val, int watch_count_val, double user_rating_val)
    : title {title_val}, watch_count {watch_count_val}, user_rating{user_rating_val}{
//        std::cout << "Primary Movie constructor called" << std::endl;
        }

Movie::Movie()
    : Movie {"No Title", 0, 0}{
//        std::cout << "Construction delegated to primary Movie constructor" << std::endl;
    }

Movie::~Movie(){
//        std::cout << "Movie destructor called!" << std::endl;
}

//NOTE: if the Movie object was ever changed to be constant, this function implementation would need a "const" qualifier
void Movie::print_summary(){
    std::cout << "\nFILM SUMMARY:" << std::endl;
    std::cout << "The name of the film is " << (*this).title << std::endl;
    std::cout << "The user has watched the film " << (*this).watch_count << " times" << std::endl;
    std::cout << "The user has given this film a rating of " << (*this).user_rating << std::endl;
}

