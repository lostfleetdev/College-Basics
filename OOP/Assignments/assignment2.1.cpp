// 2.1 write a cpp prog defines a student class to store and display student information using a constructor, and use destructor for deinitialize of all parameters

#include <iostream>

using namespace std;

class student{
public:
    int age,roll,marks,percnt;
    string name;
    student(string n, int a, int r, int m){ //using parameterised constuctor
        name = n;
        age = a;
        roll = r;
        marks = m;
       // percnt = (m / 60) * 100;
    }
    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll: " << roll << endl;
        cout << "Marks: " << marks << " / 60" << endl;
      // cout << "Percentage: " << percnt << " %" << endl;
        cout << "\n";
    }
};

/* // for default given values 
int main(){
    student s1 = student("Rahul",16,55,28);
    student s2 = student("Sujay",18,12,52);
    s1.display();
    s2.display();
    return 0;
}
*/


/* for array values given in program 
int main(){
    student std[] = {
        student("Rahul Dravid",16,55,28),
        student("Fernando Alonso",18,12,52),
        student("Max verstappen",18,13,48)
    };
    for(int i = 0;i < 3; i++){
        std[i].display();
    }
}
*/

// taking input from user

int main(){
    student std[];
    int n;
    cout << "Enter information of students." << endl;
    cout << "How many students info would u like to enter? : " ;
    cin >> n;
    string n1;
    int a1, r1, m1;
    for(int i = 0; i < n; i++){
        cout << "Student " << i + 1 << endl;
        cout << "Name: ";
        cin >> n1;
        cout << "\nAge: ";
        cin >> a1;
        cout << "\nRoll: ";
        cin >> r1;
        cout << "\nMarks: ";
        cin >> m1;
        std[i] = student(n1,a1,r1,m1);
    }

    cout << "Student Information: " << endl;
    for(int j = 0;j < n; j++){
        std[j].display();
    }
    return 0;
}