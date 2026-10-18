#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;
}

void insert(int x) {
    int index = x % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos] == x) {
            cout << "Account already exists\n";
            return;
        }

        if (table[pos] == -1) {
            table[pos] = x;
            cout << "Account inserted\n";
            return;
        }
    }

    cout << "Hash table is full\n";
}

void search(int x) {
    int index = x % SIZE;

    for (int i = 0; i < SIZE; i++) {
        int pos = (index + i) % SIZE;

        if (table[pos] == x) {
            cout << "Account found at index " << pos << endl;
            return;
        }

        if (table[pos] == -1)
            break;
    }

    cout << "Account not found\n";
}

void display() {
    cout << "Index\tAccount Number\n";

    for (int i = 0; i < SIZE; i++) {
        cout << i << "\t";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }
}

int main() {
    initialize();

    int choice, x;

    do {
        cout << "\n1. INSERT\n2. SEARCH\n3. DISPLAY\n4. EXIT\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> x;
                insert(x);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> x;
                search(x);
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit\n";
                break;

            default:
                cout << "Invalid choice\n";
        }
    } while (choice != 4);

    return 0;
}
