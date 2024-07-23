#include <iostream>

using namespace std;

double area(double r){
    return 3.14 * r * r;
}

double area(double h, double b){
    return 0.5 * h * b;
}

int area(int l, int b){
    return l * b;
}

int main(){
    int c;
    cout << "What area would you like to calculate:\n1 for triangle , 2 for circle, 3 for rectangle" << endl;
    cin >> c;
    if(c == 1){
        double h,b;
        cout << "Enter Height: ";
        cin >> h;
        cout << "\nEnter Base: ";
        cin >> b;
        cout << "\nArea: " << area(h,b) << endl;
    }
    else if(c == 2){
        int r;
        cout << "Enter Radius: ";
        cin >> r;
        cout << "\nArea: " << area(r) << endl;
    }
    else if(c == 3){
        int l,br;
        cout << "Enter Length: ";
        cin >> l;
        cout << "\nEnter Breadth: ";
        cin >> br;
        cout << "\nArea: " << area(l,br) << endl;
    }
    else{
        cout << "Enter valid input.";
    }

    return 0;
}
