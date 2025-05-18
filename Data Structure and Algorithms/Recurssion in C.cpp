#include<iostream>
using namespace std;

// Function prototypes
int fact(int);
int fib(int);
void TOH(int n, char source, char helper, char target);
int GCD(int, int);

int counter = 1;

int main() {
    cout << "Programmer - Sarfraj Alam" << endl;
    int choice;

    while (true) {
        cout << "\n\nMenu of Recursion\n";
        cout << "1. Factorial\n";
        cout << "2. Fibonacci Series\n";
        cout << "3. Tower of Hanoi\n";
        cout << "4. GCD\n";
        cout << "Choose any other option to exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the number for factorial calculation: ";
                cin >> n;
                if (n < 0) {
                    cout << "Factorial is not defined for negative numbers." << endl;
                } else {
                    cout << "The factorial of " << n << " is " << fact(n) << endl;
                }
                break;
            }

            case 2: {
                int n;
                cout << "Enter the number of terms for the Fibonacci series: ";
                cin >> n;
                if (n < 1) {
                    cout << "Please enter a positive integer greater than 0." << endl;
                } else {
                    cout << "The first " << n << " terms of the Fibonacci series are: ";
                    for (int i = 0; i < n; i++) {
                        cout << fib(i) << "\t";  // Corrected fib(1) to fib(i)
                    }
                    cout << endl;
                }
                break;
            }

            case 3: {
                int nodisk;
                cout << "Enter the number of disks for Tower of Hanoi: ";
                cin >> nodisk;
                if (nodisk < 1) {
                    cout << "Number of disks must be at least 1." << endl;
                } else {
                    char a = 'A', b = 'B', c = 'C';
                    counter = 1;  // Reset counter for each run
                    cout << "Steps to solve the Tower of Hanoi are:\n";
                    TOH(nodisk, a, b, c);
                    cout << "The minimum number of steps is: " << (1 << nodisk) - 1 << endl;
                }
                break;
            }

            case 4: {
                int x, y;
                cout << "Enter (x, y) to find GCD\n";
                cout << "x = ";
                cin >> x;
                cout << "y = ";
                cin >> y;
                cout << "The GCD value of (" << x << ", " << y << ") = " << GCD(x, y) << endl;
                break;
            }

            default:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
        }
    }
}

// Factorial using recursion
int fact(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

// Fibonacci using recursion
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

// Tower of Hanoi using recursion
void TOH(int n, char source, char helper, char target) {
    if (n == 1) {
        cout << counter << ") Move disk 1 from rod " << source << " to rod " << target << endl;
        counter++;
        return;
    }
    TOH(n - 1, source, target, helper);
    cout << counter << ") Move disk " << n << " from rod " << source << " to rod " << target << endl;
    counter++;
    TOH(n - 1, helper, source, target);
}

// GCD using recursion
int GCD(int a, int b) {
    if (b == 0)
        return a;
    else
        return GCD(b, a % b);
}
