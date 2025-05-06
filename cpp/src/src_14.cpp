#include <iostream>

using namespace std;

// 1) 문자열 길이
int StrLen(const char *str)
{
    int cnt = 0;

    // while (str[cnt])
    // while (str[cnt] != 0)
    while (str[cnt] != '\0')
        cnt++;

    return cnt;
}

// 2) 문자열 복사
char *StrCpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';

    return dest;

    /*
        char *ret = dest; // 초기값(주소) 저장

        while (*src)
        {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = 0;

        return ret; // 포인터가 다시 초기값 바라보도록
       */
}

// 3) 문자열 추가
// 주소1 [H][e][l][l][o][\0][][][][]....
// 주소2 [W][o][r][l][d][\0][][][][]....
char *StrCat(char *dest, char *src)
{
    int len = StrLen(dest); // \0
    int i = 0;

    while (src[i] != 0)
    {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
    return dest;
    /*
        char *ret = dest;
        while (*dest != '\0')
            dest++;

        while (*src != '\0')
        {
            *dest = *src;
            dest++;
            src++;
        }
        *dest = '\0';
        return ret;
         */
}

// 4) 문자열 비교
// [H][e][l][l][o][\0][][][][]....
// [H][e][l][l][a][\0][][][][]....
int StrCmp(char *a, char *b)
{
    int i = 0;

    while (a[i] != '\0' || b[i] != '\0')
    {
        if (a[i] > b[i])
            return 1;
        if (a[i] < b[i])
            return -1;
        i++; // 똑같은 경우
    }

    return 0;
}

// 5) 문자열 뒤집기
void ReverseStr(char *str)
{
    int len = StrLen(str);

    for (int i = 0; i < len / 2; i++)
    {
        int tmp = str[i]; // savew

        str[i] = str[len - 1 - i]; // switch
        str[len - 1 - i] = tmp;    // put
    }
}

int main()
{
    /* 1) 문자열 길이 */
    const int BUF_SIZE = 100;

    // [H][e][l][l][o][\0][][][][]....
    char a[BUF_SIZE] = "Hello";

    // int len = sizeof(a); // 100
    int len = strlen(a);
    int len2 = StrLen(a);
    cout << len << endl;

    /* 2) 문자열 복사 */
    char b[BUF_SIZE];

    // strcpy(b, a);

    char *cp = StrCpy(b, a);
    for (int i = 0; i < len; i++)
        cout << cp[i] << " ";
    cout << endl;

    /* 3) 문자열 덧붙이기 */
    char c[BUF_SIZE] = "World";
    // strcat(c, a);
    char *add = StrCat(a, c);
    int len3 = StrLen(add);
    for (int i = 0; i < len3; i++)
        cout << a[i] << " ";
    cout << endl;

    /* 4) 문자열 비교 */
    char arr_a[BUF_SIZE] = "Hello";
    char arr_b[BUF_SIZE] = "Hella";

    int value = StrCmp(arr_a, arr_b);
    cout << value << endl;
    // int res = strcmp(arr_a, arr_b); // 'o' - 'a' = 111 - 97 = 14
    // if (res > 0)
    //     cout << "a > b\n";
    // else if (res < 0)
    //     cout << "a < b\n";
    // else
    //     cout << "a == b\n";

    /* 5) 문자열 뒤집기 */
    ReverseStr(arr_a);
    cout << arr_a << endl;
    return 0;
}