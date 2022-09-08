# include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to Perry's Carpet Clearning, LLC" << endl;
    
    //Request user inputs
    cout << "\nHow many small rooms do you need cleaned? ";
    int small_room_count {0};
    cin >> small_room_count;
    
    cout << "How many large rooms do you need cleaned? ";
    int large_room_count {0};
    cin >> large_room_count;
    
    //Constants needed to generate a quote
    const double small_room_cost {25};
    const double large_room_cost {35};
    const double expiry_period {30};
    const double tax_rate {0.06};
    
    //Generate the quote for the customer
    cout << "\nThe cost of cleaning your small rooms is $" 
        << small_room_cost * small_room_count + small_room_cost * small_room_count * tax_rate 
        << endl;
    cout << "The cost of cleaning your large rooms is $" 
        << large_room_cost * large_room_count + large_room_cost * large_room_count * tax_rate 
        << endl;
    cout << "\nThis quote is valid for " 
        << expiry_period 
        << " days" 
        << endl;
}