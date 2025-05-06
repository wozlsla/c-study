#include <iostream>

using namespace std;

void SetMessage(const char *a)
{
    a = "Bye"; // -> .rdata Bye주소[B][y][e][\0]
}

void SetMessage(const char **a)
{
    *a = "ByeBye";
}

void SetMessage2(const char *&a)
{
    a = "wow";
}

int main()
{
    // .rdata Hello주소[H][e][l][l][o][\0]
    // msg[ Hello주소^ ] << 8 바이트
    const char *msg = "Hello";

    // [매개변수][RET][지역변수(msg(Hello주소)] | [매개변수(a(Hello주소)][RET][지역변수] -> 함수 호출
    // [매개변수][RET][지역변수(msg(Hello주소)] | [매개변수(a(Bye주소)][RET][지역변수] -> 함수 '내부' 작업
    // [매개변수][RET][지역변수(msg(Hello주소)] -> 함수 호출이 끝나면 해당 스택 프레임이 정리돼서 유효 X
    SetMessage(msg);
    cout << msg << endl;

    // Hello주소 [H][e][l][l][o][\0]
    // &msg [ Hello주소 ] << 8바이트
    // multiPtr[ &msg ] << 8바이트
    const char **multiPtr = &msg; // 다중 포인터 이기 때문에 주소값을 받음

    *multiPtr = "Bye";
    cout << msg << endl;

    // [매개변수][RET][지역변수(msg(Hello주소)] | [매개변수(a(&msg: msg의 주소)][RET][지역변수]
    SetMessage(&msg); // multiPtr
    cout << msg << endl;

    SetMessage2(msg);
    cout << msg << endl;

    return 0;
}