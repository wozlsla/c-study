#include <iostream>

using namespace std;

/*
// 선언
void Func2(int, int);

void Func1()
{
    Func2(1, 2);
}

// 정의
void Func2(int a, int b)
{
    cout << "!!" << endl;
}

int main()
{
    Func1();
}
*/

int Factorial(int n)
{
    if (n <= 1)
        return 1; // 재귀 종결 조건

    return n * Factorial(n - 1);
}

int main()
{
    int result = Factorial(1000000);
    cout << result;
}