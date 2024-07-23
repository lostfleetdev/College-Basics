#include <iostream>
#include <cstring>

using namespace std;


//default constructor
class employee{
    public:
        employee(){
           cout << "Default Constructor invoked" << endl;
        }
};


//parameterised constructors
class empl{
public:
    int id;
    string name;
    float salary;
    empl(int i, string s, float f){
        id = i;
        name = s;
        salary = f;
    }
    void display(){
        cout << id << " " << name << " " << salary << endl;
    }
};


// copy constructor
class city{
    char cname[15];
public:
    city(char c[15]){
        strcpy(cname, c);
    }
    city(city &s){
        strcpy(cname, s.cname);
    }
    void display(){
        cout << "City = " << cname << endl;
    }
};

int def(){
    employee e1;
    employee e2;
    cout << "\n";
    return 0;
}

int par(){
    empl em1 = empl(101, "jay", 86000);
    empl em2 = empl(102, "raj", 69200);
    em1.display();
    em2.display();
    cout << "\n";
    return 0;
}

int cpy(){
    city s1("Pune");
    city s2(s1);
    s1.display();
    s2.display();
    return 0;
}
/*
class stud{
public:
    int roll;
    string name;
    float perc;
    stud(int r, string n, float p);
    void display();
};

stud::stud(){
    roll = r;
    name = n;
    perc = p;
}
stud::display(){
    cout << roll << " -- " << name << " -- " << perc << endl;
}


int eg_stud(){
    stud st1 = {15,'neymar', 56.3};
    stud st2 = {46, 'fernando', 96.3};

    st1.display();
    st2.display();
    return 0;
}

*/

int main(){
    def();
    par();
    cpy();
    //eg_stud();
    return 0;
}
