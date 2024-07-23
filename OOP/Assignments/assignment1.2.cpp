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

int main(){
    struct carinfo cars[] = {{ "Porsche 911", "MH12BH5678", 2019, 8.5, 3.2},
                            { "BMW M5", "18BH7890H", 2024, 9.1, 3.3},
                            { "RB23", "MH69UH6969", 2001 ,3.1, 1.6}
    };

    for(int i = 0; i < 3; i++){
        cout << "Car            : " << cars[i].car_model << "\n"
             << "Number         : " << cars[i].car_num << "\n"
             << "Year Bought    : " << cars[i].year_bought << "\n"
             << "mileage        : " << cars[i].mil << "\n"
             << "Speed 0 to 100 : " << cars[i].sp0_100
             << "\n \n" << endl;
    }
    return 0;
}
