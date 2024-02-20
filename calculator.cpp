#include<iostream>
using namespace std;

// Function to add two numbers
double add(double num1, double num2) {
    return num1 + num2;
}

// Function to subtract two numbers
double subtract(double num1, double num2) {
    return num1 - num2;
}

// Function to multiply two numbers
double multiply(double num1, double num2) {
    return num1 * num2;
}

// Function to divide two numbers
double divide(double num1, double num2) {
    if(num2 != 0)
        return num1 / num2;
    else
        cout << "Division by zero is not allowed." << endl;
        return 0;
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        cout << "Menu:\n";
        cout << "1. Add\n";
        cout << "2. Subtract\n";
        cout << "3. Multiply\n";
        cout << "4. Divide\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 5) {
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch(choice) {
            case 1:
                result = add(num1, num2);
                break;
            case 2:
                result = subtract(num1, num2);
                break;
            case 3:
                result = multiply(num1, num2);
                break;
            case 4:
                result = divide(num1, num2);
                break;
            default:
                cout << "Invalid choice!" << endl;
                continue;
        }

        cout << "Result: " << result << endl;

    } while(choice != 5);

    return 0;
}
