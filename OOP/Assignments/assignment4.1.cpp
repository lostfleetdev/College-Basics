/*) Create a C++ program to illustrate the dynamic allocation and deallocation of memory using the new and delete operators.
 The program should demonstrate the use of pointers to manage dynamically allocated memory for both basic data types and arrays.*/

#include <iostream>
using namespace std;

int main() {
    int *ptr = new int;   
    *ptr = 42;            // Assigning a value to the allocated memory

    cout << "Value of ptr (dynamically allocated int): " << *ptr << endl;

    // Deallocate the memory
    delete ptr;

    // Dynamic allocation for an array
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int *arr = new int[size];  // Allocating memory for an array of integers

    // Assigning values to the array
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    // Displaying the values of the array
    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocate the memory for the array
    delete[] arr;

    return 0;
}
