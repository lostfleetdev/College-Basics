#include <iostream>

using namespace std;

int main(){
    int i,temp,j;
    int arr[5] = {89,56,45,47,12};
    cout << "OG array: " << endl;
    for (i = 0; i < 5; i++){
        cout << arr[i] << "\t";
    }
    cout << endl;
    for(j = 0; j < 5; j++){
        for(i = 0;i <5; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    cout << "Sorted Array: " << endl;
    for (i = 0; i < 5; i++){
        cout << arr[i] << "\t";
    }
}