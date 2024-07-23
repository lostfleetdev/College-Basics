#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // take an input as a string and store in str
    string str;
    cout << "Enter a string: " << endl;
    cin >> str;
    string rvrs = str;
    reverse(rvrs.begin(), rvrs.end());
    cout << "Revers of above is: " << rvrs << endl;

    if(str == rvrs){
        cout << "String is palindrome" << endl;
    }
    else{
        cout << "String is not palindrome" << endl;
    }

    return 0;
}