//bank acc

#include <iostream>
#include <string>

using namespace std;

struct bank_accs {
    int acc;
    string owner, addr;
    double bal;
};

int findaccindx(const bank_accs people[], int acc, int sz) {
    for (int i = 0; i < sz; i++) {
        if (people[i].acc == acc) {
            return i;
        }
    }
    return -1;
}

int printacc(const bank_accs people[], int i) {
    cout << "Displaying Account Information: " << endl;
    cout << "Account Owner: " << people[i].owner << endl;
    cout << "Account Number: " << people[i].acc << endl;
    cout << "Owner Address: " << people[i].addr << endl;
    cout << "Balance: " << people[i].bal << endl << endl;
    return 0;
}

int deposit(bank_accs people[], int i, double amount) {
    people[i].bal += amount;
    cout << "Deposit successful. New balance: " << people[i].bal << endl;
    return 0;
}

int withdraw(bank_accs people[], int i, double amount) {
    if (people[i].bal >= amount) {
        people[i].bal -= amount;
        cout << "Withdrawal successful. New balance: " << people[i].bal << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
    return 0;
}

int main() {
    bank_accs accounts[] = {
        {159, "Max", "Monaco", 753148},
        {147, "Fernando", "Spain", 78421},
        {785, "Lando", "England", 87415}
    };

    int choice, acc_num, index;
    double amount;

    while (true) {
        cout << "1. Display account information" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> acc_num;
                index = findaccindx(accounts, acc_num, 3);
                if (index != -1) {
                    printacc(accounts, index);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            case 2:
                cout << "Enter account number: ";
                cin >> acc_num;
                index = findaccindx(accounts, acc_num, 3);
                if (index != -1) {
                    cout << "Enter amount to deposit: ";
                    cin >> amount;
                    deposit(accounts, index, amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            case 3:
                cout << "Enter account number: ";
                cin >> acc_num;
                index = findaccindx(accounts, acc_num, 3);
                if (index != -1) {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    withdraw(accounts, index, amount);
                } else {
                    cout << "Account not found." << endl;
                }
                break;
            case 4:
                exit(0);
        }
    }

    return 0;
}