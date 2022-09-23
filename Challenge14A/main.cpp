#include <iostream>
#include <string>
#include <vector>

#include "Overloading.h"

void display_memory_location(const Overloading *target_array);
void display_array_elements(const Overloading *target_array);

int main()
{
//constructor testing
//------------------------------------------------------------------------    
    Overloading *const array_1 = new Overloading(1, 2, 3);
    
    std::cout << "Array 1 consists of these elements: ";
    display_array_elements(array_1);
    
    std::cout << "The memory address of the array according to the object pointer is:               " << array_1 << std::endl;
    display_memory_location(array_1); 
    
    Overloading *const array_2 = new Overloading(4, 5, 6);
    std::cout << "Array 2 consists of these elements: ";
    display_array_elements(array_2);
    
    std::cout << "The memory address of the array according to the object pointer is:               " << array_2 << std::endl;
    display_memory_location(array_2);
    
    Overloading *const array_3 = new Overloading(array_1);
    
    std::cout << "Array 3 consists of these elements: ";
    display_array_elements(array_3);
    std::cout << "Array 3 is a deep copy of Array 1, so it has a unique memory address:             " << array_3 << std::endl;
    
//overload testing
//------------------------------------------------------------------------
    //overloaded '=' operator that duplicates an array
    Overloading *const array_4 = new Overloading;
    *array_4 = *array_2;
    
    std::cout << "Array 4 consists of these elements: ";
    display_array_elements(array_4);
    std::cout << "Array 4 was created using an overloaded '=', so it has a unique memory address:   " << array_4 << std::endl;
    
    delete array_1;
    delete array_2;
    delete array_3;
    delete array_4;
    
    std::cout << "\n";
    
    return 0;
}

void display_memory_location(const Overloading *target_array){
    target_array->get_memory_address();
}

void display_array_elements(const Overloading *target_array){
    target_array->print_array();
}