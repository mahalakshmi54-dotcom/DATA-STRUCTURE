#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* insert(Node* root, int x) {
    if (root == NULL) {
        Node* t = new Node{x, NULL, NULL};
        return t;
    }

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    int a[] = {50, 30, 70, 20, 40, 60, 80};
    Node* root = NULL;

    for (int x : a)
        root = insert(root, x);

    cout << "Employee IDs in ascending order: ";
    inorder(root);

    return 0;
}
