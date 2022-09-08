#ifndef _OVERLOADING_
#define _OVERLOADING_

class Overloading
{
private:
//variables
//------------------------------------------------------------------------
    //this declaration fixes the size of the array to four elements
    int data_array [4];

//functions
//------------------------------------------------------------------------

public:
//constructor & destructor signatures
//------------------------------------------------------------------------    
    Overloading();
    Overloading(int int_1, int int_2, int int_3);
    ~Overloading(); 
    
//member method signatures
//------------------------------------------------------------------------
    void get_memory_address() const;
    void print_array();
};

#endif // _OVERLOADING_
