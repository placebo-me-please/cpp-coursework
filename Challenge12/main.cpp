#include <iostream>
#include <vector>

//FUNCTION PROTOTYPES
//----------------------------------------------------------------------------------------
//this function takes two total inputs of one types - arrays (i.e. int)
//size is not necessary because sentinel values are used to terminate pointer operations
//the function returns a pointer that points to a dynically-allocated array stored somewhere in the heap
int *apply_all(int *array_1, int *array_2); 

//this function takes one input - the array to size
//the function returns an integer value that represents the size of the array
int size_array(int *array_to_size);

//this function takes one input - the array to print
//the function returns nothing - it simply prints the array elements
void print_array(int *array_to_print);

//MAIN PROGRAM
//----------------------------------------------------------------------------------------
int main()
{

    //define the two arrays that will be used for the pointer operations
    //the arrays use sentinel values of -1 so the arrays MUST contain elements that are >= 0
    int array_1 [] {1, 2, -1};
    int array_2 [] {2, 4, 6, 8, 100, -1};
    
    //define the third array by dynamically allocating storage via pointers
    //this is just a call to the "apply_all" function
    int *array_3_ptr = {nullptr};
    array_3_ptr = apply_all(array_1, array_2);
    
    //print the three arrays out in a clean, human-readble format
    //this is just a series of calls to the "print_array" function
    std::cout << "Array 1 consists of the following elements: \n";
    print_array(array_1);
    
    std::cout << "Array 2 consists of the following elements: \n";
    print_array(array_2);
    
    std::cout << "Array 3 consists of the following elements: \n";
    print_array(array_3_ptr);
    
    //GOOD PRACTICE IS TO DELETE DYNAMICALLY ALLOCATED VALUES
    //note that only variables initialized with "new" need be deleted - that excludes arrays 1 and 2
    delete [] array_3_ptr;
}

//PROGRAM FUNCTIONS
//----------------------------------------------------------------------------------------
//see function prototypes section for a description of the functions

int *apply_all(int *array_1, int *array_2){
    
    //determine the size of the arrays AND their product - this will be the size of the third vector
    int array_1_size {0};
    array_1_size = size_array(array_1);
    
    int array_2_size {0};
    array_2_size = size_array(array_2);
    
    //dynamically allocate the memory needed to create the third array
    //one is added to the size to make room for a sentinel value that will be appended
    int *array_3 {nullptr};
    array_3 = new int[array_1_size * array_2_size + 1] {0};
    
    //nested loop sequence to multiply the array elements together and store them in the new array 
    //the "anchor" variables are needed to reset the memory addresses of arrays 2 and 3 since they are incremented by this control flow
    //REFACTOR NOTE: using a size_t variable would obviate the anchor variables since the addresses would not be incremented - possibly more safe that way!
    int *array_2_anchor {array_2};
    int *array_3_anchor {array_3};
    long int element_product {0};
    
    while (*array_1 != -1){
        while (*array_2 != -1){
            element_product = (*array_1) * (*array_2);
            *array_3 = element_product;
            array_2++, array_3++;
        }
        array_1++;
        array_2 = array_2_anchor;
    }
    //add a sentinel value to the end of the data array before returning the pointer to main
    *array_3 = -1;
    array_3 = array_3_anchor;
    return array_3;
}

int size_array(int *array_to_size){
    
    int array_size {0};
    
    while (*array_to_size != -1){
        array_size += 1;
        array_to_size++;
    }
    return array_size;
}

void print_array(int *array_to_print){
    std::cout << "[ ";
    while (*array_to_print != -1){
        std::cout << *array_to_print << " ";
        array_to_print++;
    }
    std::cout << "]\n" << std::endl;
}