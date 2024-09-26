/*ii)	Create a C++ program to demonstrate accessing members of a STUDENT
class using pointers to object members. The program should use a 
class to store student information, create an object of this class, 
and then use a pointer to access and modify the class members.*/

#include <iostream>
#include <string>
using namespace std;

class STUDENT { //creating a class STUDENT
public:
    int rollNo;
    string name;
};

int main() {
    STUDENT student;
    //assigning a pointer to 
    STUDENT *ptr = &student;

    ptr->rollNo = 101;  
    ptr->name = "Alice";

    cout << "Student Roll No: " << ptr->rollNo << endl;
    cout << "Student Name: " << ptr->name << endl;

    ptr->rollNo = 102;  
    ptr->name = "Bob";  

    cout << "Updated Student Roll No: " << ptr->rollNo << endl;
    cout << "Updated Student Name: " << ptr->name << endl;

    return 0;
}
