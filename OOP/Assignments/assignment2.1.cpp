// create a program to maintain bank accounts using class and add options to display, withdraw or add amount to account

#include <iostream>
#include <string>

using namespace std;

struct bank_accs{
    int acc;
    string owner, addr;
    double bal;
};

int findaccindx(const bank_accs people[], int acc, int sz){
    for(int i = 0; i < sz; i++){
        if(people[i].acc == acc){
            return i;
        }
    }
    return -1;
}

int printacc(const bank_accs people[], int i){
    cout << "Displaying Account Information: " << endl;
    cout << "Account Owner: " << people[i].owner << endl;
    cout << "Account Number: " << people[i].acc << endl;
    cout << "Owner Address: " << people[i].addr << endl;
    cout << "Balance: " << people[i].bal <<  "\n" << endl;
    return 0;
}

/*
class Bank{
    int acc;
};
*/

int main(){
    bank_accs accounts[] ={
        {159, "Max", "Monaco", 753148},
        {147, "Fernando", "Spain", 78421},
        {785, "Lando", "England", 87415}
    };

    int g ;
    g = findaccindx(accounts, 785, 3);
    printacc(accounts, g);
    return 0; 
}