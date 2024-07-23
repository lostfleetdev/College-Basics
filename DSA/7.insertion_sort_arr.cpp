#include <iostream>

using namespace std;

int main()
{
    int i, j, temp;
    int arr[5] = {89, 56, 45, 47, 12};
    cout << "Original array: " << endl;

    for (i = 0; i < 5; i++)
        {
        cout << arr[i] << "  ";
    }
    cout << endl;


    // Insertion Sort
    for (j = 1; j < 5; j++)
    {
        temp = arr[j];
        i = j - 1;
        while (i >= 0 && arr[i] > temp)
        {
            arr[i + 1] = arr[i];
            i = i - 1;
        }
        arr[i + 1] = temp;
    }

    cout << "Sorted array: " << endl;
    for (i = 0; i < 5; i++)
    {
        cout << arr[i] << "  ";
    }

    return 0;
}

