#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

//method signatures
void add_line_number(std::ifstream &in_file);

int main() {
    
    //open the input file and verify the operation worked
    std::ifstream in_file;
    in_file.open("rj-target.txt");
    if (!in_file){
        std::cerr << "The read file did not open correctly - please try again" << std::endl;
        return 1;
    }
    
    //call the method that adds line numbers to the text
    add_line_number(in_file);
    
    //close the file and terminate main()
    in_file.close();
    return 0;
}

//method implementations
void add_line_number(std::ifstream &in_file) {
    
    //open the output file and verify the operation worked
    std::ofstream out_file;
    out_file.open("rj-copy.txt");
    if (!out_file){
        std::cerr << "The write file did not open correctly - please try again" << std::endl;
    }
    
    //append a line number to each line via a data stream
    int i {1};
    std::string line {""};
    
    while(!in_file.eof()) {
        std::getline(in_file, line);
        if (line != "")
            out_file << std::setw(10) << std::left << i++ << line << std::endl;
        else
            out_file << "" << std::endl;
    }
    
    std::cout << "Copy operation complete - please check the file" << std::endl;
    out_file.close();
}
