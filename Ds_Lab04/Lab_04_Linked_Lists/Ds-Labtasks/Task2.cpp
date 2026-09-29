#include <iostream>
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
        }
        cout << endl;
    }

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

    return 0;
}