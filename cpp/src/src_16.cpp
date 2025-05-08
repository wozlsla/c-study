#include <iostream>
#include <iomanip>

using namespace std;

// 설계도. 클래스를 만든다고 메모리에 올라가는 게 아님!!
class Knight
{

public:
    // 기본 생성자
    Knight()
    {
        _hp = 100; // 초기화
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    // 복사 생성자 (동일한 객체)
    Knight(const Knight &knight)
    {
        _hp = knight._hp;
        _attack = knight._attack;
        _posX = knight._posX;
        _posY = knight._posY;
    }

    // 기타 생성자 - 타입 변환 생성자
    Knight(int hp)
    // explicit Knight(int hp) // 암시적(타입변환) X, 명시적으로만 사용할 때 선언
    {
        _hp = hp;
        _attack = 10;
        _posX = 0;
        _posY = 0;
    }

    // 기타 생성자
    Knight(int hp, int attack, int posY, int posX)
    {
        _hp = hp;
        _attack = attack;
        _posY = posY;
        _posX = posX;
    }

    // 멤버 함수 (선언)
    void Move(int y, int x);
    void Attack();
    void Die()
    {
        this;    // Knight *this
        _hp = 0; // this->_hp = 0 와 동일
    }

public:
    // 멤버 변수
    int _hp;
    int _attack;
    int _posX;
    int _posY;
};

// 구현부
void Knight::Move(int y, int x)
{
    _posY = y;
    _posX = x;
}

void Knight::Attack() {}

// 일반 함수
void Move(Knight *knight, int y, int x)
{
    knight->_posY = y;
    knight->_posX = x;
}

int main()
{
    // Instantiate 객체를 만듦 !
    Knight k1(100);
    // k1._hp = 100;
    k1._attack = 10;
    k1._posY = 0;
    k1._posX = 0;

    Knight k2(k1);  // 복사 생성
    Knight k3 = k1; // 복사 생성

    Knight k4; // 기본 생성자
    k4 = k1;   // + 복사

    // Knight k2; // -> 데이터로 올림
    // k2._hp = 80;
    // k2._attack = 5;
    // k2._posY = 1;
    // k2._posX = 1;

    k1.Move(2, 3);
    k1.Die();

    Move(&k1, 2, 2);

    // 암시적 형변환
    int num = 1;
    float f = (float)num; // 명시적
    double d = num;       // 암시적 (컴파일러가 처리)

    Knight k5; // 타입 변환 생성자
    k5 = 1;
    // k5 = (Knight)1; // 명시적으로 선언 했을 때, 타입 변환 사용

    return 0;
}