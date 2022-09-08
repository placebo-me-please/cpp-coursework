#include <iostream>
#include <string>
#include <vector>

#include "Movie.h"
#include "Movies.h"

Movies::Movies(){
//    std::cout << "Primary Movies constructor called" << std::endl;
}

Movies::~Movies(){
//    std::cout << "Movies destructor called!" << std::endl;
    for (auto const &movie_element : movie_vector){
        delete movie_element;
    }
}

void Movies::add_film(std::string title_val, int watch_count_val, double user_rating_val){
    
    //NOTE: for const-ness, the "const" qualifier is also needed where the movie_vector is prototyped
    //the reason is because the pointer / pointee created here are constant
    //the compiler produces an error if the vector does not share const-ness
    Movie *const film_to_push = new Movie(title_val, watch_count_val, user_rating_val);
    movie_vector.push_back(film_to_push);
}

void Movies::print_films() const {
    
    std::cout << "The user has watched the following films: " << std::endl;
    for (const auto &movie_element : movie_vector){
        movie_element->print_summary();
    }
}

void Movies::increment_watch_count(int element_index){
    ++(movie_vector.at(element_index))->watch_count;
}