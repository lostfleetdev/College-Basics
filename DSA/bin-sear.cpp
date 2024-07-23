#include <iostream>

using namespace std;

int bin_sear(int arr[], int sz, int fd){
    int low = 0,high = sz - 1 ,mid,g;
    while (low <= high){
        mid = (low + high) / 2;
        g = arr[mid];

        if (g == fd){
            return mid;
        }
        else if (g > fd){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}

int main(){
    int lst[24] = {1, 2, 4, 5, 7, 10, 11, 20, 21, 22, 32, 35, 44, 47, 51, 54, 55, 58, 65, 69, 78, 87, 96, 98};
    int c;
    c = bin_sear(lst, 24, 3);
    if (c == -1){
        cout << "Element not found in array" << endl;
    }
    else{
        cout << "Element " << lst[c] << " found at index " << c << endl;
    }
    return 0;
}