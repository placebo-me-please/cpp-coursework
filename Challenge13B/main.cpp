#include <iostream>
#include <string>

#include "Movie.h"
#include "Movies.h"

int main(){
    
    Movies *test_vector {nullptr};
    test_vector = new Movies();
    
    test_vector->add_film("The Emperor's New Groove", 10, 4.5);
    test_vector->add_film("Troll 2", 1, 0.5);
    
    test_vector->print_films();
    
    test_vector->increment_watch_count(0);
    test_vector->print_films();
    
    //DATA INTEGRITY NOTE: because the Movies class is declared as a friend in the Movie class, Movies can legally modify vector elements
    //in this context the behavior is okay - but const-ness should be used in applications where data integrity is crucial
//    test_vector.print_films();
//    test_vector.increment_watch_count(0);
//    test_vector.print_films();
    
    delete test_vector;
    return 0;
}
