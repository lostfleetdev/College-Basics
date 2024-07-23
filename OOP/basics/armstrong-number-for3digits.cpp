#include <iostream>

using namespace std;

int main(){
    int a;
    cout << "Enter a 3 digit number to check if it is an armstrong number: " << endl;
    cin >> a;
    int b = a; 
    int c = 0;
    while (b != 0){
        int d = b % 10;
        c = c + d * d * d;
        b = b / 10;
    }
    if (c == a){
        cout << "The number is an armstrong number" << endl;
    }
    else{
        cout << "The number is not an armstrong number" << endl;
    }
    return 0;
            
}