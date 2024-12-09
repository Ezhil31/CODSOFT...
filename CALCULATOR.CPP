#include <iostream>
using namespace std;
class CalculatorBase {
protected:
    double n1, n2; 
public:
    // Function to take input for numbers
    void getInput() {
        cout << "Enter the first number: ";
        cin >> n1;
        cout << "Enter the second number: ";
        cin >> n2;
    }
    void displayMenu() {
        cout << "\nSelect an operation from the following:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "Select the operation to be performed (enter 1-4): ";
    }
};
class Calculator : public CalculatorBase {
public:
    // Arithmetic operations as methods
    double add() {
        return n1 + n2;
    }
    double subtract() {
        return n1 - n2;
    }
    double multiply() {
        return n1 * n2;
    }
    double divide() {
        if (n2 == 0) {
            return -1; // Error signal for division by zero
        }
        return n1 / n2;
    }
    void calculate() {
        int choice;
        displayMenu(); 
        cin >> choice;
        double result;
        switch (choice) {
            case 1:
                result = add();
                cout << "Addition of " << n1 << " and " << n2 << " = " << result << endl;
                break;
            case 2:
                result = subtract();
                cout << "Subtraction of " << n1 << " and " << n2 << " = " << result << endl;
                break;
            case 3:
                result = multiply();
                cout << "Multiplication of " << n1 << " and " << n2 << " = " << result << endl;
                break;
            case 4:
                result = divide();
                if (result == -1) {
                    cout << "Error! Denominator cannot be zero." << endl;
                } else {
                    cout << "Division of " << n1 << " and " << n2 << " = " << result << endl;
                }
                break;
            default:
                cout << "Invalid choice! Please select a valid operation." << endl;
        }
    }
};
int main() {
    Calculator calc;
    calc.getInput();
    calc.calculate();
    return 0;
}
