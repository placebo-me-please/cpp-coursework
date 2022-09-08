#include <iostream>
#include <string>

using namespace std;

int main(){
    
    //get the user-input from the terminal using the 'getline' method
    //REFACTOR NOTE: could cap the max message length using a validation function to check the message
    string user_message;                 //initializes an empty string
    cout << "Enter a message to encrypt: ";
    getline(cin, user_message);
    cout << user_message << endl;
    
    //define the cipher that will encrypt the message
    //note that the ciper will NOT preserve the case of characters - the output is entirely capitalized
    //REFACTOR NOTE: could randomize the cipher by using a random number generator to choose ASCII character codes
    //REFACTOR NOTE: could make the .find() method agnostic to the case of the character being tested
    string std_alphabet_lower {"abcdefghijklmnopqrstuvwxyz"};
    string std_alphabet_upper {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string message_cipher {"QWERTYUIOPASDFGHJKLZXCVBNM"};
    
    //use the cipher to encrypt the message
    int char_position {};                       //the value representing the character position in the standarad alphabet
    int i {};                                   //the value representing the index position in the string message
    for (auto message_character : user_message){
        
        if (std_alphabet_lower.find(message_character) != string::npos){
            char_position = std_alphabet_lower.find(message_character);
            user_message.at(i) = message_cipher.at(char_position);
        }
        
        else if (std_alphabet_upper.find(message_character) != string::npos){
            char_position = std_alphabet_upper.find(message_character);
            user_message.at(i) = message_cipher.at(char_position);            
        }
        
        else {
            //do nothing with the character
        }
        
        i += 1;
        
    }
    
    cout << user_message << endl;
    
}