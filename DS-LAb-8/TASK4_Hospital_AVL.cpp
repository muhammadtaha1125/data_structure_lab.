#include <iostream>
using namespace std;

class Node {
public:
    int token;
    int height;
    Node* left;
    Node* right;

    Node(int value) {
        token = value;
        height = 1;
        left = NULL;
        right = NULL;
    }
};

int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return root->height;
}

int getBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return getHeight(root->left) - getHeight(root->right);
}

int maxValue(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + maxValue(getHeight(y->left), getHeight(y->right));
    x->height = 1 + maxValue(getHeight(x->left), getHeight(x->right));

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + maxValue(getHeight(x->left), getHeight(x->right));
    y->height = 1 + maxValue(getHeight(y->left), getHeight(y->right));

    return y;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->token) {
        root->left = insert(root->left, value);
    } else if (value > root->token) {
        root->right = insert(root->right, value);
    } else {
        return root;
    }

    root->height = 1 + maxValue(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    // LL Case
    if (balance > 1 && value < root->left->token) {
        return rightRotate(root);
    }

    // RR Case
    if (balance < -1 && value > root->right->token) {
        return leftRotate(root);
    }

    // LR Case
    if (balance > 1 && value > root->left->token) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // RL Case
    if (balance < -1 && value < root->right->token) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->token << " ";
    inOrder(root->right);
}

void displayTree(Node* root, int space) {
    if (root == NULL) {
        return;
    }

    space = space + 5;

    displayTree(root->right, space);

    cout << endl;
    for (int i = 5; i < space; i++) {
        cout << " ";
    }
    cout << root->token << " (H:" << root->height
         << ", BF:" << getBalance(root) << ")" << endl;

    displayTree(root->left, space);
}

int main() {
    Node* root = NULL;

    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < 7; i++) {
        root = insert(root, tokens[i]);
    }

    cout << "Appointment Tokens (In-order): ";
    inOrder(root);

    cout << endl << endl;
    cout << "Final Balanced AVL Tree:" << endl;
    displayTree(root, 0);

    return 0;
}
