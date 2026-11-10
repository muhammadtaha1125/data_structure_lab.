#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node* left;
    Node* right;

    Node(string name) {
        folder = name;
        left = NULL;
        right = NULL;
    }
};

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->folder << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << root->folder << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->folder << " ";
}

int main() {
    Node* root = new Node("C:");

    root->left = new Node("Documents");
    root->right = new Node("Pictures");

    root->left->left = new Node("Assignments");
    root->left->right = new Node("Projects");

    root->right->left = new Node("Family");
    root->right->right = new Node("Wallpapers");

    cout << "In-order: ";
    inOrder(root);

    cout << endl << "Pre-order: ";
    preOrder(root);

    cout << endl << "Post-order: ";
    postOrder(root);

    cout << endl;

    return 0;
}
