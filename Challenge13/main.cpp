#include <iostream>
#include <string>

#include "Movie.h"
#include "Movies.h"

int main(){
    
    //GENERAL NOTE: the code for this challange could be modified such that is uses raw pointers / arrays
    //pointers are not appropriate for this context, but it would be a good challenge nonetheless
    
    //ADDITIONAL FEATURES:
    //searching the Movies vector by film name
    
    Movies test_vector;
    
    //this class method is overloaded so it accepts both of of these calls
    //the former simply takes the inputs and adds them to the vector
    //the latter asks the user a series of questions to enter the film
    test_vector.add_film("The Emperor's New Groove", 10, 4);
    test_vector.add_film();
    
    //DATA INTEGRITY NOTE: because the Movies class is declared as a friend in the Movie class, Movies can legally modify vector elements
    //in this context the behavior is okay - but const-ness should be used in applications where data integrity is crucial
    test_vector.print_films();
    test_vector.increment_watch_count(0);
    test_vector.print_films();
    
    return 0;
}