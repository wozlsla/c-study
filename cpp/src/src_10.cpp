#include <iostream>

using namespace std;

// 배열 출력 함수
void PrintArray(int numbers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

// 1) Swap
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void SwapP(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 2) 정렬
// void Sort(int *numbers, int count)
void Sort(int numbers[], int count)
{
    for (int i = 0; i < count; i++)
    {
        int best = i;

        for (int j = i + 1; j < count; j++)
        {
            if (numbers[best] > numbers[j])
                best = j;
        }

        if (i != best)
            Swap(numbers[i], numbers[best]);
    }
}

// 3) 로또 번호 생성기
void Lotto(int numbers[])
{
    srand((unsigned)time(0));

    int count = 0;

    // 중복 X
    while (count != 6)
    {
        int randValue = 1 + rand() % 45; // 1~45

        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (numbers[i] == randValue)
            {
                found = true;
                break;
            }
        }

        if (found == false)
        {
            numbers[count] = randValue;
            count++;
        }
    }

    Sort(numbers, 6);
}

int main()
{
    // 1) Swap
    int a = 1;
    int b = 2;

    Swap(a, b);    // 참조
    SwapP(&a, &b); // 포인터

    cout << a << " " << b << endl;

    // 2) 정렬
    int numbers[6] = {1, 74, 23, 52, 8};
    Sort(numbers, sizeof(numbers) / sizeof(int));
    // sizeof(numbers) : 6*4 = 24
    // sizeof(int) : 4

    // cout << numbers << endl; // 주소값
    PrintArray(numbers, sizeof(numbers) / sizeof(int));

    // 3) 로또 번호 생성기
    Lotto(numbers);
    PrintArray(numbers, sizeof(numbers) / sizeof(int));

    return 0;
}