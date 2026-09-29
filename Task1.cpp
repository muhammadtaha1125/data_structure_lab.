#include <iostream>
using namespace std;
struct Node
{
    int roll;
    Node* next;
};

void add(Node*& head, int r)
{
    Node* n = new Node;
    n->roll = r;
    n->next = NULL;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        Node* t = head;

        while (t->next != NULL)
        {
            t = t->next;
        }

        t->next = n;
    }
}

void display(Node* head)
{
    Node* t = head;

    cout << "Registered Students: ";

    while (t != NULL)
    {
        cout << t->roll << " ";
        t = t->next;
    }

    cout << endl;
}

void search(Node* head, int r)
{
    Node* t = head;

    while (t != NULL)
    {
        if (t->roll == r)
        {
            cout << "Student Found";
            return;
        }

        t = t->next;
    }

    cout << "Student Not Found";
}

int main()
{
    Node* head = NULL;

    add(head, 103);
    add(head, 105);
    add(head, 108);
    add(head, 114);

    display(head);

    int r;
    cout << "Enter Roll Number to Search: ";
    cin >> r;

    search(head, r);

    return 0;
}