#include <iostream>
using namespace std;

class ATM {
private:
    double balance;
    int pin;

public:
    ATM(double initialBalance, int userPin) {
        balance = initialBalance;
        pin = userPin;
    }

    bool authenticate(int enteredPin) {
        return enteredPin == pin;
    }

    void showMenu() {
        cout << "\n--- ATM MENU ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
    }

    void checkBalance() {
        cout << "Your balance: $" << balance << endl;
    }

    void depositMoney(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdrawMoney(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }
};

int main() {
    ATM atm(1000.0, 1234); // Initial balance $1000, PIN: 1234
    int enteredPin;
    int choice;
    double amount;

    cout << "Welcome to the ATM!\n";
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    if (!atm.authenticate(enteredPin)) {
        cout << "Incorrect PIN! Access Denied.\n";
        return 1;
    }

    do {
        atm.showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                atm.checkBalance();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                atm.depositMoney(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                atm.withdrawMoney(amount);
                break;
            case 4:
                cout << "Thank you for using the ATM!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
