#include <iostream>

using namespace std;

int main(){
    int arr[6] = {2,45,89,63,47,4};
    cout << "OG array: " << endl;
    for(int j = 0; j < 6; j++){
        cout << arr[j] << "\t";
    }
    cout << endl;
    int u = 5;
    int to_upd = 69;
    arr[u] = to_upd;
    cout << "Updated Array at index " << u << " with " << to_upd << endl;
    for(int i = 0; i < 6; i++){
        cout << arr[i] << "\t";
    }
}