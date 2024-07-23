#include <iostream>

using namespace std;

int add(int x, int y){
    return x + y;
}

int add(double x, double y){
    return x + y;
}

int main(){
    int a, b;
    cout << "Enter an integer: " ;
    cin >> a;
    cout << "Enter another integer: ";
    cin >> b;
    cout << "Their addition: " << add(a,b) << endl;
    
    float q,p;
    cout << "Enter a float: ";
    cin >> q;
    cout << "Enter another float: ";
    cin >> p;
    cout << "Their Addition: " << add(q,p);
    return 0;
}