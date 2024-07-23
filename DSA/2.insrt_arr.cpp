#include <iostream>
using namespace std;

int main() {
    int arr[10] = {15, 78, 69, 45, 44}; 
    int size = 5; 
    int index = 4;
    int element = 41; 

    cout << "Original Array: " << endl;
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;
   
    for (int i = size - 1; i >= index; --i) {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;
    size++;

    cout << "Element " << element << " inserted at index " << index << endl;

    for (int i = 0; i < size; ++i) {
        cout << arr[i] << "\t";
    }
    cout << endl;

    return 0;
}
