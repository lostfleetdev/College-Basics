#include <iostream>
#include <string>

using namespace std;

struct carinfo {
    string car_model;
    string car_num;
    int year_bought;
    float mil;
    float sp0_100;
};

void addinfo(carinfo &car) {
    cout << "Add a car to the list:" << endl;
    cout << "Enter car model: ";
    cin >> ws; // To ignore any leading whitespace
    getline(cin, car.car_model);
    cout << "Enter car number: ";
    getline(cin, car.car_num);
    cout << "Enter year bought: ";
    cin >> car.year_bought;
    cout << "Enter mileage: ";
    cin >> car.mil;
    cout << "Enter speed 0 to 100: ";
    cin >> car.sp0_100;
}

int main(){
    struct carinfo cars[4] = {
        { "Porsche 911", "MH12BH5678", 2019, 8.5, 3.2 },
        { "BMW M5", "18BH7890H", 2024, 9.1, 3.3 },
        { "RB23", "MH69UH6969", 2001 , 3.1, 1.6 }
    };

    addinfo(cars[3]);

    cout << "\nList of cars:" << endl;
    for(int i = 0; i < 4; i++){
        cout << "Car            : " << cars[i].car_model << "\n"
             << "Number         : " << cars[i].car_num << "\n"
             << "Year Bought    : " << cars[i].year_bought << "\n"
             << "Mileage        : " << cars[i].mil << "\n"
             << "Speed 0 to 100 : " << cars[i].sp0_100
             << "\n \n" << endl;
    }
    return 0;
}
