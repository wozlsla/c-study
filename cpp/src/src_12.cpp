#include <iostream>

using namespace std;

int main()
{

    int first[5] = {1, 2, 3, 5, 3};
    int sec[5] = {8, 2, 9, 5, 7};

    int apart2D[2][5] = {{1, 2, 3, 5, 3}, {8, 2, 9, 5, 7}};

    for (int floor = 0; floor < 2; floor++)
    {
        for (int room = 0; room < 5; room++)
        {
            int num = apart2D[floor][room];
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}