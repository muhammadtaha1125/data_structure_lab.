#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node* left;
    Node* right;

    Node(string name) {
        category = name;
        left = NULL;
        right = NULL;
    }
};

void BFS(Node* root) {
    if (root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    cout << "Categories in BFS order: ";

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->category << " ";

        if (current->left != NULL) {
            q.push(current->left);
        }

        if (current->right != NULL) {
            q.push(current->right);
        }
    }

    cout << endl;
}

int main() {
    Node* root = new Node("Electronics");

    root->left = new Node("Clothing");
    root->right = new Node("Mobiles");

    root->left->left = new Node("Men");
    root->left->right = new Node("Women");

    root->right->left = new Node("Laptops");
    root->right->right = new Node("Accessories");

    BFS(root);

    return 0;
}
