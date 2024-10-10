#include <iostream>
using namespace std;

double add(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}

double multiply(double x, double y) {
    return x * y;
}

double divide(double x, double y) {
    if (y == 0) {
        cout << "Error: Division by zero is not allowed" << endl;
        return 0;
    }
    return x / y;
}

int main() {
    double num1, num2;
    int choice;

    cout << "Select operation:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;

    cout << "Enter choice (1/2/3/4): ";
    cin >> choice;

    if (choice >= 1 && choice <= 4) {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        switch (choice) {
            case 1:
                cout << "Result: " << add(num1, num2) << endl;
                break;
            case 2:
                cout << "Result: " << subtract(num1, num2) << endl;
                break;
            case 3:
                cout << "Result: " << multiply(num1, num2) << endl;
                break;
            case 4:
                cout << "Result: " << divide(num1, num2) << endl;
                break;
            default:
                cout << "Invalid operation" << endl;
                break;
        }
    } else {
        cout << "Invalid choice. Please select a valid operation." << endl;
    }

    return 0;
}
