// Section 17
// Challenge 1
/***********************************************************************************************************
Create a program that has the following:

1. a function named make that creates and returns a unique_ptr to a vector of shared_ptrs to Test objects. 

2. a function named fill that expects a vector of shared pointers to Test objects and a int
   representing the number of Test objects to create dynamically and add to the vector.
   
   This function will prompt the user to enter an integer, create a shared_ptr to a Test object 
   initialized to the entered integer and add that shared pointer to the vector.
   
3. a function named display that expects a vector of shared_ptrs to Test object and displays the
   data in each Test object
   
4. The main driver should look as follows:

    int main() {
        std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
        vec_ptr = make();
        std::cout << "How many data points do you want to enter: ";
        int num;
        std::cin >> num;
        fill(*vec_ptr, num);
        display(*vec_ptr);
        return 0;
    }
    
Below is a sample run for the user entering 3 at the console:
    
How many data points do you want to enter: 3
Enter data point [1] : 10
        Test constructor (10)
Enter data point [2] : 20
        Test constructor (20)
Enter data point [3] : 30
        Test constructor (30)
Displaying vector data
=======================
10
20
30
=======================
        Test destructor (10)
        Test destructor (20)
        Test destructor (30)

- I am providing the function prototypes in the code. 
However, feel free to modify these as you wish
***********************************************************************************************************/
#include <iostream>
#include <memory>
#include <vector>

class Test {
private:
    int data;
public:
    Test() 
        : data{0} 
        { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    
    Test(int data) 
        : data {data} 
        { std::cout << "\tTest constructor (" << data << ")" << std::endl; }
    
    int get_data() const {
        return data;
    }
    
    ~Test() 
        {std::cout << "\tTest destructor (" << data << ")" << std::endl; }
};

// Function prototypes
std::unique_ptr<std::vector<std::shared_ptr<Test>>> make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>>&vec);

int main() {
    
    //vec_ptr is a smart pointer to a vector that contains smart pointers to objects of type <Test>
    //make() must therefore return a unique pointer
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();

    //the user specifies how many integer objects they want to create
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    
    //vec_ptr is filled with the number of objects specified by the user
    fill(*vec_ptr, num);

    display(*vec_ptr);
    return 0;
}

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
//the purpose of this function is to create an instance of a vec_ptr smart pointer object
    
    //the RHS of this expression must match the return type specified by the function signature
    auto ptr = std::make_unique <std::vector<std::shared_ptr<Test>>> ();
    std::cout << "make() function called" << std::endl;
    
    return ptr;
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
//the purpose of this function is to generate a user-specified number of <int> objects

    //control flow
    int user_entry {0};
    for (int i = 0; i < num; i++) {
    
        //user entry (no validation implemented)
        std::cout << "Enter data point [" << i + 1 << "]: ";
        std::cin >> user_entry;
        
        //shared pointer creation & push-back
        auto ptr = std::make_shared <Test> (user_entry);
        vec.push_back(ptr);
    }
    
    std::cout << "fill() function called" << std::endl;
}

void display(const std::vector<std::shared_ptr<Test>>&vec) {
//the purpose of this function is to display the <int> values stored in the <Test> objects

    std::cout << "This vector contains <Test> objects with the following values:" << std::endl;
    
    //control flow
    for (auto const &vec_element : vec)
        std::cout << vec_element->get_data() << std::endl;
}