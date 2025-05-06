#include <iostream>

using namespace std;

// 배열은 함수 인자로 넘기면, 컴파일러가 알아서 포인터로 치환(char[] -> char*)
// 즉, 배열의 내용 전체를 넘긴게 아님. 시작 주소(포인터)만 넘김.
void Test(char a[])
{
    a[0] = 'x';
}

int main()
{
    "Hello World";

    // .rdata 주소[H][e][l][l][o][\0]
    // test[ 주소^ ] << 8 byter (64bit)
    const char *test = "Hello";

    // .rdata 주소[H][e][l][l][o][\0]
    // [H][e][l][l] | [o][\0]
    // test2 = 주소 -> 즉, 포인터처럼 주소 바구니를 새로 만드는 게 아닌 바구니 그 자체
    char test2[] = "Hello";

    // 포인터는 [주소를 담는 바구니]
    // 배열은 [][]... 그 자체. 같은 데이터끼리 붙어있는 '바구니 모음'
    // - 배열 이름은 '바구니 모음'의 시작 주소

    // test2[0] = "R"; // const char* (최소 2byte : 'R' + '\0')
    test2[0] = 'R'; // char (1byte)

    Test(test2);
    cout << test2; // xello

    return 0;
}