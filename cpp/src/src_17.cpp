#include <iostream>
#include <iomanip>

using namespace std;

// 메모리
// [   Knight   ]
// [ [ Player ] ]
class Player
{
public:
    Player()
    {
        _hp = 0;
        _attack = 0;
        _defence = 0;
        cout << "Player 생성자 호출" << endl;
    }

    Player(int hp)
    {
        _hp = hp;
        _attack = 0;
        _defence = 0;
        cout << "Player 생성자(int hp) 호출" << endl;
    }

    ~Player() { cout << "~Player 소멸자 호출" << endl; }

    void Move()
    {
        cout << "Parents" << endl;
    }
    void Attack() {}
    void Die() {}

public:
    int _hp;
    int _attack;
    int _defence;
};

class Knight : public Player
{
public:
    Knight()
    {
        /*
        선처리 영역
        - 여기서 Player() 생성자 호출
        */
        _stamina = 0;
        cout << "Knight 생성자 호출" << endl;
    }

    Knight(int stamina) : Player(100)
    {
        /*
        선처리 영역 - 생성자 지정 가능
        */
        _stamina = stamina;
        cout << "Knight 생성자(int hp) 호출" << endl;
    }

    ~Knight()
    {
        cout << "~Knight 소멸자 호출" << endl;
    }
    /*
    후처리 영역
    - 여기서 Player() 소멸자 호출
    */

    void Move() { cout << "Child" << endl; }; // 재정의

public:
    int _stamina;
};

class Mage : public Player
{
public:
public:
    int _mp;
};

int main()
{
    Knight k;

    k._hp = 100;

    k.Move();
    // k.Player::Move();

    Knight k2(50);
}