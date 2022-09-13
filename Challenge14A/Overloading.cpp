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

Overloading::Overloading(Overloading *const source_array)

    : Overloading {0, 0, 0}
{
    std::cout << "Deep Copy Constructor Called" << std::endl;
    
    //assign the RHS array values to the newly initialized LHS object
    bool sentinel {false};
    int i = 0;
    while (!sentinel){
        if (source_array->data_array[i] == -1){
            sentinel = true;
            data_array[i+1] = -1;
        }
        else {
            data_array[i] = source_array->data_array[i];
            i++;
        }
    }
}

Overloading::~Overloading()
{
    std::cout << "Primary Destructor Called" << std::endl;
    //Note: 'delete' does not need to be called because data_array is automatically added to the stack
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

//member overloaders
//------------------------------------------------------------------------
//Overloading &Overloading::operator=(const Overloading &rhs){
//    std::cout << "Overload called: object duplicated" << std::endl;
//    
////    //check if the LHS object is already equal to the RHS object
////    if (this == &rhs){
////        return *this;
////    }
//    
//    //de-allocate the memory for the new object, then initialize it
//    delete [] this->data_array;
//    
//    //REFACTOR NOTE: create a member method that measures the size of an array
//    //then use that method to determine how large to make the new array
//    
//    //assign the RHS array values to the newly initialized LHS object
//    bool sentinel {false};
//    int i = 0;
//    while (!sentinel){
//        if (rhs.data_array[i] == -1){
//            sentinel = true;
//            this->data_array[i+1] = -1;
//            return *this;
//        }
//        else {
//            this->data_array[i] = rhs.data_array[i];
//            i++;
//        }
//    }
//}