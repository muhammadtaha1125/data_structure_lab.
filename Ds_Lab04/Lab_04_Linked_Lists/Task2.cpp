#include <iostream>
<<<<<<< HEAD
using namespace std;
int main() 
{
    int a[4][5] = {
        {1, 0, 1, 1, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 1, 1, 1, 1}
    };

    int o = 0, e = 0;

    cout << "Parking Layout:\n";

    for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 5; j++) 
        {
            cout << a[i][j] << " ";
            
            if (a[i][j] == 1)
                o++;
            else
                e++;
=======
#include <string>
using namespace std;
struct Node {
    string patientID;
    Node* next;

    Node(string id) 
    {
        patientID = id;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() 
    {
        head = nullptr;
    }

    void enqueue(string id) 
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

    void dequeue() {
        if (head == nullptr) 
        {
            cout << "No patients in the queue." << endl;
            return;
        }
        Node* temp = head;
        cout << "Patient " << temp->patientID << " is being served." << endl;
        head = head->next;
        delete temp;
    }

    void displayQueue() {
        if (head == nullptr) 
        {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << temp->patientID;
            if (temp->next != nullptr) 
            {
                cout << " -> ";
            }
            temp = temp->next;
>>>>>>> 5f8b891 (Added Lab 04 Linked Lists files)
        }
        cout << endl;
    }

<<<<<<< HEAD
    cout << "\nTotal occupied spaces: " << o << endl;
    cout << "Total empty spaces: " << e << endl;

    int r, c;

    cout << "\nEnter row number (1-4): ";
    cin >> r;

    cout << "Enter column number (1-5): ";
    cin >> c;

    if (a[r - 1][c - 1] == 0)
        cout << "Parking space is available." << endl;
    else
        cout << "Parking space is occupied." << endl;

    cout << "\nTotal parking capacity: 20" << endl;
    cout << "Current occupancy: " << o << endl;
=======
    ~PatientQueue() {
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
    PatientQueue queue;

    queue.enqueue("P101");
    queue.enqueue("P102");
    queue.enqueue("P103");
    queue.enqueue("P104");

    cout << "Waiting Patients:" << endl;
    queue.displayQueue();
    cout << endl;

    queue.dequeue();
    cout << endl;

    cout << "Updated Queue:" << endl;
    queue.displayQueue();
>>>>>>> 5f8b891 (Added Lab 04 Linked Lists files)

    return 0;
}