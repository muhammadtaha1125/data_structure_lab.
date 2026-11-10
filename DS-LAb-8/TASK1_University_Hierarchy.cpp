#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* left;
    Node* right;

    Node(string memberName) {
        name = memberName;
        left = NULL;
        right = NULL;
    }
};

void displayTree(Node* root) {
    if (root == NULL) {
        return;
    }

    cout << "Member: " << root->name << endl;

    if (root->left != NULL) {
        cout << "Left Child: " << root->left->name << endl;
    } else {
        cout << "Left Child: None" << endl;
    }

    if (root->right != NULL) {
        cout << "Right Child: " << root->right->name << endl;
    } else {
        cout << "Right Child: None" << endl;
    }

    cout << endl;

    displayTree(root->left);
    displayTree(root->right);
}

int main() {
    Node* root = new Node("HOD");

    root->left = new Node("Coordinator 1");
    root->right = new Node("Coordinator 2");

    root->left->left = new Node("Faculty Member 1");
    root->left->right = new Node("Faculty Member 2");

    root->right->left = new Node("Faculty Member 3");
    root->right->right = new Node("Faculty Member 4");

    cout << "University Department Hierarchy" << endl << endl;
    displayTree(root);

    return 0;
}
