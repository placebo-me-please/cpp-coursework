#include <iostream>
#include <string>
#include <vector>

#include "Overloading.h"

void display_memory_location(const Overloading *target_array);

int main()
{
//    //building the arrays that will be operated on
//    int elements_1 [4] {1, 2, 3, -1};
//    int *const array_1 {elements_1};
//    std::cout << "Array 1 contains the following elements : ";
//    print_array(array_1);

    Overloading *const array_1 = new Overloading(1, 2, 3);
    
    std::cout << "Array 1 consists of these elements: ";
    array_1->print_array();
    
    std::cout << "The memory address of the array according to the object pointer is:       " << array_1 << std::endl;
    display_memory_location(array_1); 
    
    //NEXT STEP: Optimize the memory management and const-ness of Overloading class
    
    //overloaded '+' operator that concatenates two arrays to produce a third array
    
    //overloaded '-' operator that "pops" the last element of an array off
    
    delete array_1;
    std::cout << "\n";
    return 0;
}

void display_memory_location(const Overloading *target_array){
    target_array->get_memory_address();
}