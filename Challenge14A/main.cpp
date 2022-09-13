#include <iostream>
#include <string>
#include <vector>

#include "Overloading.h"

void display_memory_location(const Overloading *target_array);
void display_array_elements(const Overloading *target_array);

int main()
{
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
    
//    //overloaded '=' operator that duplicates an array
//    Overloading *copy_array = new Overloading;
//    (*copy_array).operator=array_1;
//    std::cout << "The memory address of the copied array according to the object pointer is:        " << copy_array << std::endl;
    
    //overloaded '+' operator that concatenates two arrays to produce a third array
    
    //overloaded '-' operator that "pops" the last element of an array off
    
    delete array_1;
    delete array_2;
//    delete copy_array;
    
    std::cout << "\n";
    
    return 0;
}

void display_memory_location(const Overloading *target_array){
    target_array->get_memory_address();
}

void display_array_elements(const Overloading *target_array){
    target_array->print_array();
}