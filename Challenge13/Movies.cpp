#include <iostream>
#include <string>
#include <vector>

#include "Movie.h"
#include "Movies.h"

Movies::Movies()
    : movie_vector {}{
//    std::cout << "Primary Movies constructor called" << std::endl;
}

Movies::~Movies(){
//    std::cout << "Movies destructor called!" << std::endl;
}

void Movies::add_film(){

    //REFACTOR NOTE: add a validation that prevents an empty entry (but how do I call in a function not local to this Class?)
    std::string title_val {};
    std::cout << "Enter the name of the film: " << std::flush;
    std::getline(std::cin, title_val);
   
    //REFACTOR NOTE: add validation 
    int watch_count_val {};
    std::cout << "Enter the number of times you have watched the film: " << std::flush;
    std::cin >> watch_count_val;
    
    //BUG NOTE: this results in an integer being displayed instead of a double
    //REFACTOR NOTE: add validation
    double user_rating_val {};
    std::cout << "Enter your rating of the film (scale of 1-5): " << std::flush;
    std::cin >> user_rating_val;
    
    //this two-liner is necessary to prevent a bug due to the mixing of getline() and cin
    std::cin.clear();
    std::cin.ignore(1000,'\n');

    Movie film_to_push(title_val, watch_count_val, user_rating_val);
    movie_vector.push_back(film_to_push);
}

void Movies::add_film(std::string title_val, int watch_count_val, double user_rating_val){

    Movie film_to_push(title_val, watch_count_val, user_rating_val);
    movie_vector.push_back(film_to_push);
}

void Movies::print_films(){
    
    //NOTE: the & operator serves as an alias to the vector element (i.e. an individual Movie object)
    //it is implemented as a best practice for building efficient code
    std::cout << "The user has watched the following films: " << std::endl;
    for (Movie &movie_element : movie_vector){
        movie_element.print_summary();
    }
}

void Movies::increment_watch_count(int element_index){
    
    ++movie_vector.at(element_index).watch_count;
}

