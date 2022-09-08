#ifndef _MOVIES_
#define _MOVIES_

#include <iostream>
#include <string>
#include <vector>

#include "Movie.h"

class Movies
{
//all elements of the vector, and the vector itself, are private to prevent alteration
//only public methods within this class can modify the private variables
//this class is a friend to the Movie class too
private:
    std::vector <Movie> movie_vector;
    
public:
//methods
    void add_film();
    void add_film(std::string title_val, int watch_count_val, double user_rating_val);
    void print_films();
    void increment_watch_count(int element_index);

//constructors
    Movies();
    ~Movies();
};

#endif // _MOVIES_
