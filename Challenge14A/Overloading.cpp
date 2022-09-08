#include <iostream>

#include "Overloading.h"

//constructors & destructor
//------------------------------------------------------------------------
Overloading::Overloading()
    
    : Overloading {0, 0, 0}
{
    std::cout << "No-Arguments Constructor Called" << std::endl;
}

Overloading::Overloading(int int_1, int int_2, int int_3)

    : data_array {int_1, int_2, int_3, -1}
{
    std::cout << "Primary Constructor Called" << std::endl;
}

Overloading::~Overloading()
{
    std::cout << "Primary Destructor Called" << std::endl;
}

//member functions
//------------------------------------------------------------------------
void Overloading::get_memory_address() const{
    std::cout << "The memory address of the array according to the data_array memeber variable is:  " << data_array << std::endl;
}

void Overloading::print_array() const{
    
    const int *tmp_ptr {data_array};
    
    std::cout << "[ ";
    
    bool sentinel {false};
    while (!sentinel){
        if (*tmp_ptr == -1){
            sentinel = true;
        }
        else {
            std::cout << *tmp_ptr << " ";
            tmp_ptr++;
        }
    }
    
    std::cout << "]" << std::endl;
}