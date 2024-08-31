#include <iostream>

using namespace std;


// a simple function to display a line at end of a program
void endline(){
    cout << "\n" << endl;
    for(int i = 0;i < 20;i++){
        cout << "==" ;
    }
    cout << "\n" << endl;
}

//printing an array
int prntele(int ar[],int sz){
    for(int i = 0; i < sz; i++){
        cout << "element " << i << " : " << ar[i] << endl;
    }
    return 0;
}

//traverse of an array
int travrs(int ar[], int sz){
    cout << "Array elements: " ;
    for(int i = 0;i < sz; i++){
        cout << ar[i] << "\t";
    }
    return 0;
}

//bubble sorting an array
int bblsrt(int arr[], int sz){
    int temp;
    for(int j = 0; j < sz-1; j++){
        for(int i = 0;i < sz-j-1; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    travrs(arr, sz);
    return 0;
}

//updating an array by replacing an element 
int upd(int arr[], int indx, int ele){
    arr[indx] = ele;
    return 0;
}

int insrt(int arr[], int sz, int at_indx, int ele){
    for(int i = sz;i <= at_indx; --i){
        arr[i-1] = arr[i];
    }
    arr[at_indx] = ele;
    return 0;
}

int del(int arr[], int sz, int del_elmnt){
    for(int i = del_elmnt; i < sz; i++){
        arr[i] = arr[i+1];
    }
    return 0;
}

int main(){
    int arr[5] = {18,92,65,12,1};//array used for: printing, traverse, bubble sort, 

    cout << "Printing an Array: " << endl;
    prntele(arr, 5);
    endline();
    
    cout << "Traversing an Array: " << endl;
    travrs(arr, 5);
    endline();
    
    cout << "Sorting the above array using bubble sort: " << endl;
    bblsrt(arr, 5);
    endline();

    cout << "Updatng the above array by replacing an element: " << endl;
    upd(arr, 3, 69);
    travrs(arr, 5);
    endline();

    cout << "Inserting an element in the array: " << endl;
    int aray[10] = {34,69,67,24,46};
    insrt(arr, 5, 2, 43);
    travrs(arr, 6);
    endline();

    cout << "Deleting an element in the array" << endl;
    int ar[10] = {2,6,69,58,1,7};
    del(ar, 6, 2);
    travrs(ar,6);
    endline();
    
    return 0;
}