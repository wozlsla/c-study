#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int *ptr = &a;

    int value = *ptr;
    *ptr = 2;
}