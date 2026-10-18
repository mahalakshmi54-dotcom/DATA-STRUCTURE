#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> garage;
    int choice;
    string car;

    do {
        cout << "\n1. Park Car\n2. Remove Car";
        cout << "\n3. Display Top Car\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car number: ";
            cin >> car;
            garage.push(car);
            cout << "Car parked.\n";
            break;

        case 2:
            if (garage.empty()) {
                cout << "Garage is empty.\n";
            } else {
                cout << "Car removed: "
                     << garage.top() << '\n';
                garage.pop();
            }
            break;

        case 3:
            if (garage.empty())
                cout << "Garage is empty.\n";
            else
                cout << "Top car: "
                     << garage.top() << '\n';
            break;

        case 4:
            break;

        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
