#include <iostream>

using namespace std;
struct StatInfo
{
    int hp = 0xAAAAAAAA; // 초기값 세팅
    int attack = 0xBBBBBBBB;
    int defence = 0xDDDDDDDD;
};

int main()
{
    // TYPE 이름[개수];
    const int monsterCount = 10;
    StatInfo monsters[monsterCount];

    // TYPE* 포인터 : StatInfo* WhoAmI
    auto WhoAmI = monsters;

    // 주소[ (100,10,1) ] | StatInfo[ ] | StatInfo[ ] | ...
    StatInfo *monster_0 = monsters;
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    // StatInfo[ ] | 주소[ (200,20,2) ] | StatInfo[ ] | ...
    StatInfo *monster_1 = monsters + 1; // StatInfo타입 바구니 하나 이동
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // pointer <-> reference
    // StatInfo[ ] | StatInfo[ ] | monster_2.주소[ ] | ...
    StatInfo &monster_2 = *(monsters + 2);
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // 위와 완전 다른 작동. monsters[2]의 내용물을 복사하여 -> 그 복사된 객체(tmp)에 작업
    StatInfo tmp;
    tmp = *(monsters + 2);
    tmp.hp = 300;
    tmp.attack = 30;
    tmp.defence = 3;

    // loop
    for (int i = 0; i < 0; i++)
    {
        StatInfo &monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = (i + 1);
    }

    // Index
    // *(monsters + i); = monsters[i]
    for (int i = 0; i < 0; i++)
    {
        monsters[i].hp = 100 * (i + 1);
        monsters[i].attack = 10 * (i + 1);
        monsters[i].defence = (i + 1);
    }

    // 배열 초기화
    // int numbers[5]; // 영역 할당
    int numbers[5] = {};                // 0으로 초기화
    int numbers1[10] = {1, 2, 3, 4, 5}; // 설정 안 한 값들은 0으로 초기화
    int numbers1[] = {1, 2, 43, 41, 5}; // 데이터 개수만큼의 크기에 해당하는 배열 생성

    return 0;
}