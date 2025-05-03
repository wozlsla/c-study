/* 연습문제 01 */
#include <iostream>

using namespace std;

int main()
{

    int input;
    cin >> input;

    // 별 1
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 별 2
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 별 3
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < (input - i); j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // 구구단
    for (int i = 2; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cout << i << "*" << j << "=" << (i * j) << endl;
        }
    }

    return 0;
}