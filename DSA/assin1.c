#include <stdio.h>
#include <conio.h>

void endl(){
    printf("\n");
    for (int i = 0; i < 40; i++)
    {
        printf("==");
    }
    printf("\n\n");
}

// printing and traversing an array
void prnt_array(int ar[], int s){
    for(int i = 0; i < s; i++){
        printf("Element %d = %d \n", i , ar[i]);
    }
}
void travrs_array(int ar[], int s){
    printf("Elements of array:\t");
    for(int i = 0; i < s; i++){
        printf("%d \t", ar[i]);
    }
}

// modifying an array: 
void upd(int ar[], int indx, int ele){
    ar[indx] = ele;
}


//Sorting :Bubble Sorting
void bbl_srt(int ar[], int s){
    int temp;
    for(int j = 0; j < s-1; j++){
        for(int i = 0; i < s-j-1; i++){
            if(ar[i] >= ar[i+1]){
                temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp;
            }
        }
    }
    travrs_array(ar, s);
}


int main(){
    int arr[5] = {1,5,3,4,8};
    prnt_array(arr, 5);
    endl();
    travrs_array(arr, 5);
    endl();
    upd(arr, 2, 2);
    travrs_array(arr, 5);
    endl();
    bbl_srt(arr, 5);

    return 0;   
}
