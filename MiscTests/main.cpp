#include <iostream>

int main() {

    int *p {nullptr};
    
    std::cout << "This machine allocates " << sizeof(p) << " bytes for pointer addresses" << std::endl;
    
    std::cout << "\nThe following is a demonstration of how pointers handle addresses:\n";
    
    int var_x {};               //value of x is zero
    int *x_point {&var_x};     //the pointer must be of the same type
    
    x_point = &var_x;
    
    std::cout << "\nThe address of variable 'x', determined using the '&' symbol, is:     " << &var_x << std::endl;
    std::cout << "The address of variable 'x', determined using the pointer method, is: " << x_point << std::endl;
    
    std::cout << "The value of *x_point after it is assigned the address &x_var is: " << *x_point << std::endl;
    std::cout << "The value of x_var can be altered via the pointer too: ";
    
    *x_point = 20;
    std::cout << var_x << std::endl;
    
    std::cout << "\n";
    return 0;
}
