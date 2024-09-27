#include <iostream>
#include <cstdlib> 
using namespace std;

int main() {
    //malloc()
    int *ptr = (int *)malloc(sizeof(int)); 
    *ptr = 10;
    cout << "Value using malloc: " << *ptr << endl;

    //calloc()
    int *ptr2 = (int *)calloc(1, sizeof(int));  
    // Calloc initial to 0
    cout << "Value using calloc (initialized to 0): " << *ptr2 << endl;

    //realloc()
    ptr2 = (int *)realloc(ptr2, 2 * sizeof(int));  
    ptr2[1] = 20;  
    cout << "After reallocating, second value: " << ptr2[1] << endl;

    // Freeing memory
    free(ptr);
    free(ptr2);

    return 0;
}
