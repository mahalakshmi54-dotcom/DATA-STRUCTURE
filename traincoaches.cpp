#include <iostream>
using namespace std;

struct Node {
    int coach;
    Node* next;
};

Node* head = nullptr;

void addBeginning(int value) {
    Node* temp = new Node{value, head};
    head = temp;
}

void addEnd(int value) {
    Node* temp = new Node{value, nullptr};

    if (head == nullptr) {
        head = temp;
        return;
    }

    Node* p = head;
    while (p->next != nullptr)
        p = p->next;

    p->next = temp;
}

void removeCoach(int value) {
    Node* p = head;
    Node* prev = nullptr;

    while (p != nullptr && p->coach != value) {
        prev = p;
        p = p->next;
    }

    if (p == nullptr) {
        cout << "Coach not found.\n";
        return;
    }

    if (prev == nullptr)
        head = p->next;
    else
        prev->next = p->next;

    delete p;
    cout << "Coach removed.\n";
}

void display() {
    Node* p = head;

    if (p == nullptr) {
        cout << "No coaches.\n";
        return;
    }

    while (p != nullptr) {
        cout << "Coach" << p->coach << " -> ";
        p = p->next;
    }
    cout << "NULL\n";
}

int main() {
    int choice, value;

    do {
        cout << "\n1. Add Beginning\n2. Add End";
        cout << "\n3. Remove Coach\n4. Display";
        cout << "\n5. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter coach number: ";
            cin >> value;
            addBeginning(value);
            break;
        case 2:
            cout << "Enter coach number: ";
            cin >> value;
            addEnd(value);
            break;
        case 3:
            cout << "Enter coach number to remove: ";
            cin >> value;
            removeCoach(value);
            break;
        case 4:
            display();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}
