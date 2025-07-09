#include <iostream>
#include <cmath>
#include <string>
#include <limits>
#include <iomanip>  // For output precision

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

// Converts degrees to radians
double toRadians(double degree) {
    return degree * (M_PI / 180.0);
}

// Calculates factorial
unsigned long long factorial(int n) {
    if (n < 0) return 0;
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

// Display menu
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

// Input validation for numeric values
bool getValidatedInput(double& num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid input. Please enter a number.\n";
        return false;
    }
    return true;
}

bool getValidatedIntInput(int& num) {
    cin >> num;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "❌ Invalid input. Please enter an integer.\n";
        return false;
    }
    return true;
}

int main() {
    int choice;
    double num1, num2;
    int n;

    cout << fixed << setprecision(6); // Set precision for floating point outputs

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid choice. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter two numbers: ";
            if (getValidatedInput(num1) && getValidatedInput(num2))
                cout << "Result: " << num1 + num2 << endl;
            break;

        case 2:
            cout << "Enter two numbers: ";
            if (getValidatedInput(num1) && getValidatedInput(num2))
                cout << "Result: " << num1 - num2 << endl;
            break;

        case 3:
            cout << "Enter two numbers: ";
            if (getValidatedInput(num1) && getValidatedInput(num2))
                cout << "Result: " << num1 * num2 << endl;
            break;

        case 4:
            cout << "Enter two numbers: ";
            if (getValidatedInput(num1) && getValidatedInput(num2)) {
                if (num2 != 0)
                    cout << "Result: " << num1 / num2 << endl;
                else
                    cout << "Error: Division by zero.\n";
            }
            break;

        case 5:
            cout << "Enter base and exponent: ";
            if (getValidatedInput(num1) && getValidatedInput(num2))
                cout << "Result: " << pow(num1, num2) << endl;
            break;

        case 6:
            cout << "Enter number: ";
            if (getValidatedInput(num1)) {
                if (num1 >= 0)
                    cout << "Result: " << sqrt(num1) << endl;
                else
                    cout << "Error: Negative input for sqrt.\n";
            }
            break;

        case 7:
            cout << "Enter angle in degrees: ";
            if (getValidatedInput(num1))
                cout << "Result: " << sin(toRadians(num1)) << endl;
            break;

        case 8:
            cout << "Enter angle in degrees: ";
            if (getValidatedInput(num1))
                cout << "Result: " << cos(toRadians(num1)) << endl;
            break;

        case 9:
            cout << "Enter angle in degrees: ";
            if (getValidatedInput(num1))
                cout << "Result: " << tan(toRadians(num1)) << endl;
            break;

        case 10:
            cout << "Enter number: ";
            if (getValidatedInput(num1)) {
                if (num1 > 0)
                    cout << "Result: " << log10(num1) << endl;
                else
                    cout << "Error: log undefined for non-positive numbers.\n";
            }
            break;

        case 11:
            cout << "Enter number: ";
            if (getValidatedInput(num1)) {
                if (num1 > 0)
                    cout << "Result: " << log(num1) << endl;
                else
                    cout << "Error: ln undefined for non-positive numbers.\n";
            }
            break;

        case 12:
            cout << "Enter integer (0 - 20): ";
            if (getValidatedIntInput(n)) {
                if (n >= 0 && n <= 20)
                    cout << "Result: " << factorial(n) << endl;
                else
                    cout << "Error: Factorial only supported for 0 to 20.\n";
            }
            break;

        case 0:
            cout << "Exiting Calculator. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
