#include <stdio.h>

// a simple function to display a line at end of a program
void endline(){
    printf("\n");
    for(int i = 0; i < 20; i++){
        printf("==");
    }
    printf("\n\n");
}

//printing an array
void prntele(int ar[], int sz) {
    printf("Array Elements:\n");
    for(int i = 0; i < sz; i++) {
        printf("element %d : %d\n", i, ar[i]); 
    }
}


//traverse of an array
void travrs(int ar[], int sz){
    printf("Array elements: ");
    for(int i = 0; i < sz; i++){
        printf("%d\t", ar[i]);
    }
}

//bubble sorting an array
void bblsrt(int arr[], int sz){
    int temp;
    for(int j = 0; j < sz-1; j++){
        for(int i = 0; i < sz-j-1; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    travrs(arr, sz);
}

//updating an array by replacing an element
void upd(int arr[], int indx, int ele){
    arr[indx] = ele;
}


// this function inserts an element between 2 elements
void insrt(int arr[], int sz, int at_indx, int ele){
    for(int i = sz; i > at_indx; --i){
        arr[i] = arr[i-1];
    }
    arr[at_indx] = ele;
}

// function deletes and shifts all other elements to prior position
void del(int arr[], int sz, int del_elmnt){
    for(int i = del_elmnt; i < sz-1; i++){
        arr[i] = arr[i+1];
    }
}

// function to take input and 
void createArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

int main(){
    int n; //array used for: printing, traverse, bubble sort
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    createArray(arr, n);

    endline();
    printf("Printing an Array: \n");
    prntele(arr, n);
    endline();
    
    printf("Traversing an Array: \n");
    travrs(arr, n);
    endline();
    
    printf("Sorting the above array using bubble sort: \n");
    bblsrt(arr, n);
    endline();
    
    printf("Updating the above array by replacing an element at index 3 with 69: \n");
    upd(arr, 3, 69);
    travrs(arr, n);
    endline();
    
    printf("Inserting an element in the array: \n");
    int aray[10] = {34, 69, 67, 24, 46};
    insrt(aray, 5, 2, 43);
    travrs(aray, 6);
    endline();
    
    printf("Deleting an element in the array: \n");
    int ar[10] = {2, 6, 69, 58, 1, 7};
    del(ar, 6, 2);
    travrs(ar, 5);
    endline();
    
    return 0;
}
