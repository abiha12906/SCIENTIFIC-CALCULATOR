#include <iostream>
#include <cmath>
#include <string>
#include <limits>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Function to convert degrees to radians
double toRadians(double degree) {
    return degree * (M_PI / 180);
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

// Main calculator menu
void displayMenu() {
    cout << "\n--- Scientific Calculator ---\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Power (x^y)\n";
    cout << "6. Square Root\n";
    cout << "7. Sine\n";
    cout << "8. Cosine\n";
    cout << "9. Tangent\n";
    cout << "10. Log (base 10)\n";
    cout << "11. Natural Log (ln)\n";
    cout << "12. Factorial\n";
    cout << "0. Exit\n";
    cout << "-----------------------------\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double num1, num2;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 + num2 << endl;
            break;

        case 2:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 - num2 << endl;
            break;

        case 3:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 * num2 << endl;
            break;

        case 4:
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero.\n";
            break;

        case 5:
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            cout << "Result: " << pow(num1, num2) << endl;
            break;

        case 6:
            cout << "Enter number: ";
            cin >> num1;
            if (num1 >= 0)
                cout << "Result: " << sqrt(num1) << endl;
            else
                cout << "Error: Negative input for sqrt.\n";
            break;

        case 7:
            cout << "Enter angle in degrees: ";
            cin >> num1;
            cout << "Result: " << sin(toRadians(num1)) << endl;
            break;

        case 8:
            cout << "Enter angle in degrees: ";
            cin >> num1;
            cout << "Result: " << cos(toRadians(num1)) << endl;
            break;

        case 9:
            cout << "Enter angle in degrees: ";
            cin >> num1;
            cout << "Result: " << tan(toRadians(num1)) << endl;
            break;

        case 10:
            cout << "Enter number: ";
            cin >> num1;
            if (num1 > 0)
                cout << "Result: " << log10(num1) << endl;
            else
                cout << "Error: log undefined for non-positive numbers.\n";
            break;

        case 11:
            cout << "Enter number: ";
            cin >> num1;
            if (num1 > 0)
                cout << "Result: " << log(num1) << endl;
            else
                cout << "Error: ln undefined for non-positive numbers.\n";
            break;

        case 12:
            int n;
            cout << "Enter integer: ";
            cin >> n;
            if (n >= 0)
                cout << "Result: " << factorial(n) << endl;
            else
                cout << "Error: Factorial not defined for negative numbers.\n";
            break;

        case 0:
            cout << "Exiting Calculator. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (choice != 0);

    return 0;
}
