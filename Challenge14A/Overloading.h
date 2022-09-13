#ifndef _OVERLOADING_
#define _OVERLOADING_

class Overloading
{
private:
//variables
//------------------------------------------------------------------------
    //this declaration fixes the size of the array to four elements
    //the last element is always a sentinel value of -1
    int data_array [4];

//functions
//------------------------------------------------------------------------

public:
//constructor & destructor signatures
//------------------------------------------------------------------------    
    Overloading();
    Overloading(int int_1, int int_2, int int_3);
    Overloading(Overloading *const source_array);
    ~Overloading(); 
    
//member method and overloading signatures
//------------------------------------------------------------------------
    void get_memory_address() const;
    void print_array() const;
    
//    Overloading &operator=(const Overloading &rhs);
};

#endif // _OVERLOADING_
