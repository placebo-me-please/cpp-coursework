#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    //1D VECTOR CREATION
    //REFACTOR NOTE: consider adding the two elements in a single line instead of two
	vector <int> vector_1 {};
    vector_1.push_back(10);
    vector_1.push_back(20);
    
    vector <int> vector_2 {};
    vector_2.push_back(100);
    vector_2.push_back(200);
    
    cout << "Element 1 of vector_1 is " << vector_1.at(0) << " and element 2 of vector_1 is " << vector_1.at(1) << endl;
    cout << "Element 1 has " << vector_1.size() << " elements\n" << endl;
    
    cout << "Element 2 of vector_2 is " << vector_2.at(0) << " and element 2 of vector_2 is " << vector_2.at(1) << endl;
    cout << "Element 1 has " << vector_2.size() << " elements\n" << endl;
    
    //2D VECTOR CREATION
    vector < vector <int>> vector_2d {};
    vector_2d.push_back(vector_1);
    vector_2d.push_back(vector_2);
    
    cout << "Here is the 2D vector:" << endl;
    cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    
    //BEHAVIOR TEST
    //test the following to observe the result
    
    vector_1.at(0) = 1000;
    cout << "\nThe following is a test:" << endl;
    cout << "Element 1 of vector_1 is " << vector_1.at(0) << " and element 2 of vector_1 is " << vector_1.at(1) << endl;
    
    cout << "\nHere is the 2D vector again:" << endl;
    cout << vector_2d.at(0).at(0) << "  " << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << " " << vector_2d.at(1).at(1) << endl;
    
    //RESULT: changing vector_1 does not affect vector_2d
    //i.e. vector_1 is not linked in any way to vector_2d
    //pointers are a solution to this problem
    
    return 0;
}
