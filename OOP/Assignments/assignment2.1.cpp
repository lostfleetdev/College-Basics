#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    int accountNumber;
    string owner;
    string address;
    double balance;

public:
    BankAccount(int accNum, string own, string addr, double bal) {
        accountNumber = accNum;
        owner = own;
        address = addr;
        balance = bal;
    }

    //deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // withdraw money with balance check
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". Remaining balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds for withdrawal." << endl;
        } else {
            cout << "Withdrawal amount must be positive." << endl;
        }
    }

    //display account information
    void displayInfo() const {
        cout << "\nDisplaying Account Information:" << endl;
        cout << "Account Owner: " << owner << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Address: " << address << endl;
        cout << "Balance: $" << balance << "\n" << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

int findAccountIndex(const BankAccount accounts[], int acc, int size) {
    for (int i = 0; i < size; i++) {
        if (accounts[i].getAccountNumber() == acc) {
            return i;
        }
    }
    return -1;
}

int main() {
    BankAccount accounts[] = {
        BankAccount(159, "Max", "Monaco", 753148),
        BankAccount(147, "Fernando", "Spain", 78421),
        BankAccount(785, "Lando", "England", 87415)
    };

    int index = findAccountIndex(accounts, 785, 3);
    if (index != -1) {
        accounts[index].displayInfo();  // display initial info
        accounts[index].deposit(10000); // deposit money
        accounts[index].withdraw(5000); // withdraw money
    } else {
        cout << "Account not found." << endl;
    }

    return 0;
}
