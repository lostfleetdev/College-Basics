#include <iostream>
using namespace std;

class DB;

class DM {
public:
    float meters, centimeters;

    DM(float m = 0, float cm = 0) : meters(m), centimeters(cm) {}

    friend DM addDistances(DM d1, DB d2);
};

class DB {
public:
    float feet, inches;

    DB(float ft = 0, float in = 0) : feet(ft), inches(in) {}

    friend DM addDistances(DM d1, DB d2);
};

DM addDistances(DM d1, DB d2) {
    float totalCM = (d1.meters * 100 + d1.centimeters) + (d2.feet * 30.48 + d2.inches * 2.54);
    return DM(totalCM / 100, totalCM - (static_cast<int>(totalCM / 100) * 100));
}

int main() {
    DM d1(2, 50);
    DB d2(5, 8);

    DM result = addDistances(d1, d2);
    cout << "Total Distance: " << result.meters << " meters " << result.centimeters << " centimeters" << endl;

    return 0;
}
