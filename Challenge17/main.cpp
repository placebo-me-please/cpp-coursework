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