#include <iostream>
using namespace std;
<<<<<<< HEAD
int main() 
{
    int a[6][4];
    int t[6] = {};
    double av[6];

    for (int i = 0; i < 6; i++) 
    {
        cout << "Enter marks for Student " << i + 1 << ":\n";

        for (int j = 0; j < 4; j++) 
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> a[i][j];
        }
    }

    cout << "\nMarks Table:\n";
    cout << "Student\tEng\tMath\tProg\tAI\n";

    for (int i = 0; i < 6; i++) 
    {
        cout << i + 1 << "\t";

        for (int j = 0; j < 4; j++) 
        {
            cout << a[i][j] << "\t";
            t[i] += a[i][j];
        }

        cout << endl;
    }

    cout << "\nTotal Marks:\n";
    for (int i = 0; i < 6; i++)
        cout << "Student " << i + 1 << ": " << t[i] << endl;

    cout << "\nAverage Marks:\n";
    for (int i = 0; i < 6; i++) 
    {
        av[i] = t[i] / 4.0;
        cout << "Student " << i + 1 << ": " << av[i] << endl;
    }

    cout << "\nHighest Marks in Each Subject:\n";

    for (int j = 0; j < 4; j++) 
    {
        int h = a[0][j];

        for (int i = 1; i < 6; i++) 
        {
            if (a[i][j] > h)
                h = a[i][j];
        }

        cout << "Subject " << j + 1 << ": " << h << endl;
    }

    int h = t[0];
    int s = 0;

    for (int i = 1; i < 6; i++) 
    {
        if (t[i] > h) 
        {
            h = t[i];
            s = i;
        }
    }

    cout << "\nStudent with Highest Total Marks: Student "
         << s + 1 << " (" << h << ")" << endl;
=======
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
>>>>>>> 5f8b891 (Added Lab 04 Linked Lists files)

    return 0;
}