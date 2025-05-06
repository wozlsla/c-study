#include <iostream>

using namespace std;

int main()
{

    int arr[2][2] = {{1, 2}, {3, 4}};

    // // 주소1[ ?? ]
    // // pp[ 주소1 ]
    // int **pp = (int **)arr; // X

    // [1][2] [3][4]
    // [ 주소 ]
    int (*p2)[2] = arr;

    cout << (*p2)[0] << endl;
    cout << (*p2)[1] << endl;
    cout << (*(p2 + 1))[0] << endl;
    cout << (*(p2 + 1))[1] << endl;

    cout << p2[0][0] << endl;
    cout << p2[0][1] << endl;
    cout << p2[1][0] << endl;
    cout << p2[1][1] << endl;

    return 0;
}