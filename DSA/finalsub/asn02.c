#include <stdio.h>

// Function to print the array
int prnt_ar(int arr[], int sz, char g){
    if(g == 'o'){
        printf("Original Array: \n");
    }
    else if(g == 'r'){
        printf("Sorted Array: \n");
    }
    
    for(int i = 0; i < sz; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}

// Bubble sort
int bblsrt(int arr[], int sz){
    int temp, cnt = 0;
    for(int j = 0; j < sz; j++){
        for(int i = 0; i < sz - 1; i++){
            if(arr[i] > arr[i + 1]){
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

// Insertion sort
int insrt_srt(int arr[], int sz){
    int i, j, k, cnt = 0;
    for(i = 1; i < sz; i++){
        k = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > k){
            arr[j + 1] = arr[j];
            j = j - 1;
            cnt++;
        }
        arr[j + 1] = k;
    }   
    return cnt;  
}

int main(){
    int ar[100], s;
    printf("Program to Show use of sorting techniques\n");
    printf("Enter the size of your array: ");
    scanf("%d", &s);
    printf("Enter %d elements: \n", s);
    
    for(int i = 0; i < s; i++){
        scanf("%d", &ar[i]);
    }
    
    prnt_ar(ar, s, 'o');
    
    int chs, co;
    printf("Select sorting method to be used on array: \n1 for Bubble sort\n2 for Insertion Sort\n");
    scanf("%d", &chs);
    
    switch(chs){
    case 1:
        printf("Array Sorted With Bubble sort: \n");
        co = bblsrt(ar, s);
        prnt_ar(ar, s, 'r');
        break;
    
    case 2:
        printf("Array sorted with Insertion sort: \n");
        co = insrt_srt(ar, s);
        prnt_ar(ar, s, 'r');
        break;
    
    default:
        printf("Enter valid option.\n");
        break;
    }
    
    printf("Steps required: %d\n", co);
    
    return 0;
}
    