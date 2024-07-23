// Question: write a c++ program to calculate volume of a cylinder, cube and cuboid by using function overloading.

#include <iostream>

using namespace std;

double vol(double a){
    //cube
    return a*a*a;
}

double vol(double l, double b, double h){
    //cuboid
    return l*b*h;
}

double vol(double r, double h){
    //cylinder
    return 3.14*r*r*h;
}

int main(){
    int w;
    double sid, len, bred, cub_h, rad, cyl_h;
    cout << "What voulme would u like to calculate?" << endl;
    cout << "1 for cube\n2 for cuboid\n3 for cylinder" << endl;
    cin >> w;
    if (w == 1){
        cout << "Enter Side length: ";
        cin >> sid;
        cout << "Volume of cube: " << vol(sid);
    }
    else if (w == 2){
        cout << "Enter length: ";
        cin >> len;
        cout << "Enter breadth: ";
        cin >> bred;
        cout << "Enter heigh: ";
        cin >> cub_h;
        cout << "Volume of cuboid: " << vol(len, bred, cub_h);
    }
    else if (w == 3){
        cout << "Enter redius: ";
        cin >> rad;
        cout << "Enter height: ";
        cin >> bred;
        cout << "Volume of cylinde: " << vol(rad, cyl_h);
    }
    else{
        cout << "Enter Valid Argument";
    }

    return 0;
}
