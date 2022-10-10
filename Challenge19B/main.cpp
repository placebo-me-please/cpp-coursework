#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

struct Student {
    std::string const name;
    std::string const response;
    int score {0};
};

//method signatures
std::vector <Student> data_builder(std::ifstream &read_file);
void response_scorer (std::vector <Student> &response_vector);
void score_printer (std::vector <Student> &response_vector);

int main(){
    
    //verify that the file has been opened
    std::ifstream in_file;
    in_file.open("test_responses.txt");
    if (!in_file){
        std::cerr << "The file did not open correctly - please try again" << std::endl;
        return 1;
    }
    
    //build the data vector and print the score results
    std::vector <Student> test_data {};
    test_data = data_builder(in_file);
    response_scorer(test_data);
    score_printer(test_data);
    
    //close the file
    in_file.close();
    
	return 0;
}

std::vector <Student> data_builder(std::ifstream &read_file){
//this function fetches the scoring template, and the student names / scores
    
    int i {0};
    std::string line {};
    std::vector <Student> test_data;
    std::string temp_name {};
    std::string temp_response {};
    
    while (!read_file.eof()){
        
        std::getline(read_file, line);
        
        if (i == 0) {
            Student student_struct {"MASTER", line, 0};
            test_data.push_back(student_struct);
        }
        
        else if (i % 2 != 0)
            temp_name = line;
        
        else if (i % 2 == 0) {
            temp_response = line;
            Student student_struct {temp_name, temp_response, 0};
            test_data.push_back(student_struct);
        }
    i++;
    }
    return test_data;
}

void response_scorer (std::vector <Student> &response_vector) {
//this function determines and prints the scores of each student 
    
    int i {0};
    int j {0};
    std::string const score_template {response_vector.at(0).response};
    
    for (auto student : response_vector) {
        
        //this skips the score response template (i.e. first row)
        if (i == 0) {
            i++;
            continue;
        }
        
        //this examines each sutdent's response letter by letter (i.e. substring)
        else if (i != 0) {
            
            j = 0;
            
            for (auto &selection : student.response) {
                if (selection == score_template[j])
                    response_vector.at(i).score += 1;
            j++;
            }
        }
        i++;
    }
}

void score_printer (std::vector <Student> &response_vector) {
//this function displays the scores in a neatly-formatted table

        std::cout << std::setw(10) << std::left << "Name" << std::setw(10) << std::right << "Score" << std::endl;
        std::cout << std::setw(20) << std::setfill('-') << "" << std::endl;
        std::cout << std::setfill(' ');
        
        int i {0};
        
        for (auto student : response_vector) {
            if (i != 0)
            std::cout << std::setw(10) << std::left << student.name << std::setw(10) << std::right << student.score << std::endl;
        i++;
        }
}