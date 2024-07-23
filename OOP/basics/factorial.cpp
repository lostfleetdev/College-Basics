#include <iostream>

using namespace std;

int fact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}

int main(){
    int a;
    cout << "Enter a Digit for Factorial: " << endl;
    cin >> a;
    cout << "Factorial of " << a << " is " << fact(a) << endl;
    return 0;
}
