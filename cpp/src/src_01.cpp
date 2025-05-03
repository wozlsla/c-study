/* 데이터 01 */
#include <iostream>
#include <locale>

using namespace std;

/*
    byte(8bits) - word(2byte, 16bits) - dword(4byte, 32bits) - qword(8byte, 64bits)

    0이 아닌 초기화 값이 있는 변수 .data 영역
    초기값이 0 or 없는 변수 .bss 영역
    로컬 변수는 모두 스택(stack)에 저장됨
*/

/* 1. Integer */
char a;            // 1 byte (-128~127)
unsigned char ua;  // 1 byte (0~255)
short b;           // 2 byte (-32,768~32,767)
unsigned short ub; // 2 byte (0~65,536)
int c;             // 4 byte (-21.4억~21.4억)
long d;            // 8byte (on 64-bit systems) / __int64 (MSVC에서 사용) ??

/* 2. Boolean */
// bool: true/false : 1 byte integer
// 어셈블리에서 bool은 없음
bool isPlayer = true;

/* 3. Real number, 부동(움직이는)소수점
    프로그램에서 근사값임 -> 수가 커질수록 오차 범위도 매우 커짐, == 으로 비교 X */
float attackSpeed = -3.375f; // 4 byte = 부호(1) 지수(8) 유효숫자(23)
double attackSpeed2 = 0.689; // 8 byte = 부호(1) 지수(11) 유효숫자(52)

// 이진수 변환 => 0b11.011
// 3 = 0b11
// 0.375 = 0.5*0 + 0.25*1 + 0.125*1 = 0b0.011
// 정규화 0b1.1011 * 2^1 : 1(부호) 1(지수) 1011(유효숫자)
// 저장 결과 : 0b 1 1000'0000  1011000'0000'0000'0000'0000

/* 4. 문자와 문자열
    char: 알파벳, 숫자, 문자 (영어)
    char_t: unicode 문자 (전 세계 모든 문자에 대해 유일 코드 부여한 것) 중 UTF16
    C스타일 문자열의 마지막엔 \00(종료: ASCII 0번 null)이 들어가있음
유니코드 표기 방식은 여러가지가 있는데, 대표적으로
UTF8
- 알파벳, 숫자: 1byte (ASCII 동일한 번호)
- 유럽 지역의 문자: 2byte
- 한글, 한자 등: 3byte
UTF16
- 알파벳, 숫자, 한글, 한자 등 거의 대부분 문자: 2byte
- 예외적인 고대문자: 4byte
(windows / macos,linux 시스템에 따라 인코딩 방식이 다르다)
*/

char ch = 97;
// char ch = 'a';
char ch2 = '1'; // 일반 ASCII 문자

wchar_t wch = L'안'; // 와이드 문자 (유니코드 코드 포인트)

int main()
{
    // 정수 오버플로우
    b = 32767;
    b = b + 1;
    // cout << b << endl;

    // 정수 언더플로우
    ub = 0;
    ub = ub - 1;
    // cout << ub << endl;

    // C++ 스트림 로케일 설정
    wcout.imbue(locale("ko_KR.UTF-8")); // macOS
    // wcout.imbue(locale("kor")); // windows

    // cout << wch << endl;  // 50504 (0xC548) (안)
    wcout << wch << endl; // xecx95x88 (안)
    cout << "안녕, macOS!" << endl;
    wcout << L"안녕, mac!" << endl;

    return 0;
}