#include <iostream>

using namespace std;

int prnt_ar(int arr[],int sz, char g){
    if(g == 'o'){
        cout << "OG Array: " << endl;
    }
    else if(g == 'r'){
        cout << "Sorted Array: " << endl;
    }
    
    for(int i = 0;i < sz;i++){
        cout << arr[i] << "\t";
    }
    cout << "\n";
    return 0;
}

//Bubble sort
int bblsrt(int arr[], int sz){
    int temp,cnt = 0;
    for(int j = 0; j < sz; j++){
        for(int i = 0;i < sz-1; i++){
            if(arr[i] > arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                cnt++;
            }
        }
    }
    return cnt;
}

//Insertion sort

int insrt_srt(int arr[], int sz){
    int i,j,k,cnt = 0;
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
    cout << "Program to Show use of sorting techniques" << endl;
    cout << "Enter the size of your array: ";
    cin >> s;
    cout << "Enter " << s << " elements: " << endl; 
    for(int i = 0; i < s; i++){
        cin >> ar[i];
    } 
    prnt_ar(ar, s, 'o');

    int chs;
    cout << "Select sorting method to be used on array: \n1 for Bubble sort\n2 for Insertion Sort" << endl;
    cin >> chs;
    int co; //number of steps conducted by sorting techniques returned by respective functions
    switch(chs)
    {
    case 1:
        cout << "Array Sorted With Bubble sort: " << endl;
        co = bblsrt(ar,s);
        prnt_ar(ar,s,'r');
        break;
    
    case 2:
        cout << "Array sorted with innsertion sort: "<< endl;
        co = insrt_srt(ar,s);
        prnt_ar(ar,s,'r');
        break;

    default:
        cout << "Enter valid option." << endl;
        break;
    }
    cout << "Steps required : " << co;
    return 0;
}

