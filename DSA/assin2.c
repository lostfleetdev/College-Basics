#include <stdio.h>
#include <conio.h>

void prnt_arr(int ar[], int s){
    for(int i = 0; i < s; i++){
        printf("%d\t", ar[i]);
    }
    printf("\n");
}

//bubble sort
void bbl_sort(int ar[], int s){
    int temp;
    for(int j = 0; j < s; j++){
        for(int i = 0; i < s-j; i++){
            if(ar[i] < ar[i+1]){
                temp = ar[i];
                ar[i] = ar[i+1];
                ar[i+1] = temp; 
            }
        }
    }
    prnt_arr(ar,s);
}

int main(){
    int array[5] = {7,4,5,1,2};
    prnt_arr(array, 5);
    bbl_sort(array, 5);
    return 0;
}