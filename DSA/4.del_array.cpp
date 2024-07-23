#include <iostream>

using namespace std;

int main(){
    int arr[5] = {2,5,68,4,7};
    int del = 2;
    cout << "OG array: " << endl;
    for(int j = 0; j < 5; j++){
        cout << arr[j] << "\t";
    }
    cout << endl;
    for(int i = del; i < 5; i++){
        arr[i] = arr[i+1];
    }
    cout << "Array with element deleted at index " << del << ": "<< endl;
    for(int z=0; z<4; z++){
        cout << arr[z] << "\t";
    }
    return 0;
}
