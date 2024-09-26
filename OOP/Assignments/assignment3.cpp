#include <iostream>
#include <cmath>

using namespace std;

void showMenu() {
    cout << "Scientific Calculator Menu:" << endl;
    cout << "1. Square root" << endl;
    cout << "2. Exponential (e^x)" << endl;
    cout << "3. Logarithm (base 10)" << endl;
    cout << "4. Sine" << endl;
    cout << "5. Cosine" << endl;
    cout << "6. Tangent" << endl;
    cout << "7. Exit" << endl;
}

int main() {
    int choice;
    double num;

    do {
        showMenu();
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        if (choice >= 1 && choice <= 6) {
            cout << "Enter the number: ";
            cin >> num;
        }

        switch (choice) {
            case 1:
                cout << "Square root of " << num << " = " << sqrt(num) << endl;
                break;
            case 2:
                cout << "Exponential of " << num << " = " << exp(num) << endl;
                break;
            case 3:
                cout << "Logarithm (base 10) of " << num << " = " << log10(num) << endl;
                break;
            case 4:
                cout << "Sine of " << num << " = " << sin(num) << endl;
                break;
            case 5:
                cout << "Cosine of " << num << " = " << cos(num) << endl;
                break;
            case 6:
                cout << "Tangent of " << num << " = " << tan(num) << endl;
                break;
            case 7:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please choose a valid option." << endl;
        }
        cout << endl;
    } while (choice != 7);

    return 0;
}
