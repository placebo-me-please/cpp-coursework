#ifndef _MOVIE_
#define _MOVIE_

#include <iostream>
#include <string>

class Movie
{
//all attributes of the movie are private to prevent alteration
//these attributes can only be modified via calls to the public methods
//the Movies class is declared as a friend so it has access to the members of this class
private:
//friends
    friend class Movies;
//variables
    std::string title;
    int watch_count;
    double user_rating;

public:
//methods
    void print_summary();
//constructors
    Movie(std::string title_val, int watch_count_val, double user_rating_val);
    Movie();
    ~Movie();
};

#endif // _MOVIE_
