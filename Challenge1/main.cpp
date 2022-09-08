#include <iostream>

int main()
{
    int fav_num;
    std::cout << "Please enter your favorite number, 1-100: ";
    std::cin >> fav_num;
    std::cout << "Hey! " << fav_num << " is also my favorite number." << std::endl;
    return 0;
}