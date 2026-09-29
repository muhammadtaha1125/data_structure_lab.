#include <iostream>
<<<<<<< HEAD
using namespace std;
int main() 
{
    int a[3][3] = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int b[3][3] = 
    {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int c[3][3];

    cout << "Matrix A:\n";

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }

    cout << "\nMatrix B:\n";

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            c[i][j] = a[i][j] + b[i][j];
    }

    cout << "\nSum of Matrix A and B:\n\n";

    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }
=======
#include <string>
using namespace std;
struct Node 
{
    string productID;
    Node* next;

    Node(string id) 
    {
        productID = id;
        next = nullptr;
    }
};

class ShoppingCart {
private:
    Node* head;

public:
    ShoppingCart() 
    {
        head = nullptr;
    }

    void addProduct(string id) 
    {
        Node* newNode = new Node(id);
        if (head == nullptr) 
        {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) 
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void removeProduct(string id) 
    {
        if (head == nullptr) 
        {
            cout << "Cart is empty." << endl;
            return;
        }

        cout << "Remove Product: " << id << endl;

        if (head->productID == id) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr && current->productID != id) 
        {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Product " << id << " not found in the cart." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }

    void displayCart() {
        if (head == nullptr) 
        {
            cout << "Cart is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->productID;
            if (temp->next != nullptr) 
            {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    ~ShoppingCart() {
        while (head != nullptr) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() 
{
    ShoppingCart cart;

    cart.addProduct("P101");
    cart.addProduct("P205");
    cart.addProduct("P310");
    cart.addProduct("P415");

    cout << "Shopping Cart:" << endl;
    cart.displayCart();
    cout << endl;

    cart.removeProduct("P310");
    cout << endl;

    cout << "Updated Cart:" << endl;
    cart.displayCart();
>>>>>>> 5f8b891 (Added Lab 04 Linked Lists files)

    return 0;
}