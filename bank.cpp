#include <iostream>
using namespace std;

const int SIZE = 10;
int table[SIZE];

void insert(int x) {
    int i = x % SIZE;
    while (table[i] != -1)
        i = (i + 1) % SIZE;
    table[i] = x;
}

void search(int x) {
    int i = x % SIZE, start = i;

    while (table[i] != -1) {
        if (table[i] == x) {
            cout << "Account found at index " << i << endl;
            return;
        }
        i = (i + 1) % SIZE;
        if (i == start) break;
    }
    cout << "Account not found\n";
}

void display() {
    for (int i = 0; i < SIZE; i++)
        cout << i << " : " << table[i] << endl;
}

int main() {
    for (int i = 0; i < SIZE; i++)
        table[i] = -1;

    insert(25);
    insert(35);
    insert(15);
    insert(42);

    cout << "Hash Table:\n";
    display();

    search(35);
    search(99);

    return 0;
}
