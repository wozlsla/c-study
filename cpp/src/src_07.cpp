#include <iostream>

using namespace std;

struct StatInfo
{
    int hp;      // +0
    int attack;  // +4
    int defence; // +8
};

StatInfo CreatePlayer();
void EnterLobby();
void CreateMonster(StatInfo *info);
bool StartBattle(StatInfo *player, StatInfo *monster);

int main()
{
    EnterLobby();
    return 0;
}

void EnterLobby()
{
    cout << "로비에 입장했습니다" << endl;

    StatInfo player;
    player.hp = 0xbbbbbb;
    player.attack = 0xbbbbbb;
    player.defence = 0xbbbbbb;

    // [매개변수][RET][지역변수(temp(c,c,c), player(b,b,b))]
    // | [매개변수(&temp)][RET][지역변수(ret(100,10,2))] -> temp(100,10,2) 이렇게 '복사' -> player에 넣어줌
    player = CreatePlayer();

    StatInfo monster;
    monster.hp = 0xbbbbbb;
    monster.attack = 0xbbbbbb;
    monster.defence = 0xbbbbbb;

    // [매개변수][RET][지역변수(monster(40,8,2))]
    // | [매개변수(&monster)][RET][지역변수()]
    CreateMonster(&monster);

    bool win = StartBattle(&player, &monster);

    if (win)
        cout << "승리" << endl;
    else
        cout << "패배" << endl;
}

StatInfo CreatePlayer()
{
    cout << "플레이어 생성" << endl;

    StatInfo ret;

    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
}

void CreateMonster(StatInfo *info)
{
    cout << "몬스터 생성" << endl;

    info->hp = 40;
    info->attack = 8;
    info->defence = 1;
}

bool StartBattle(StatInfo *player, StatInfo *monster)
{
    while (true)
    {
        int damage = player->attack - monster->attack;
        if (damage < 0)
            damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;

        cout << "몬스터 HP: " << monster->hp << endl;

        if (monster->hp == 0)
            return true;

        damage = monster->attack - player->attack;
        if (damage < 0)
            damage = 0;

        cout << "플레이어 HP: " << player->hp << endl;

        player->hp -= damage;
        if (player->hp < 0)
            player->hp = 0;

        if (player->hp == 0)
            return false;
    }
}
