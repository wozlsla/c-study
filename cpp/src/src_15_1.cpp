#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            // cout << board[y][x] << " ";
            cout << setfill('0') << setw(2) << board[y][x] << " ";
        }
        cout << endl;
    }
}

// 풀이
enum DIR
{
    RIGHT,
    DOWN,
    LEFT,
    UP
};

bool CanGo(int y, int x)
{
    // 유효 범위 확인
    if (y < 0 || y >= N)
        return false;
    if (x < 0 || x >= N)
        return false;

    // 방문 확인
    if (board[y][x] != 0)
        return false;

    return true;
}

void SetBoard()
{
    // 1 0 0 0 0
    //         0

    int dir = RIGHT; // 방향
    int num = 1;     // 위치
    int y = 0;       // 좌표
    int x = 0;       // 좌표

    while (true)
    {
        board[y][x] = num; // 위치

        if (num == N * N) // 종결 조건
            break;

        // 이동 방향에 따른 다음 좌표 계산
        int nextY;
        int nextX;

        switch (dir)
        {
        case RIGHT:
            nextY = y;
            nextX = x + 1;
            break;
        case DOWN:
            nextY = y + 1;
            nextX = x;
            break;
        case LEFT:
            nextY = y;
            nextX = x - 1;
            break;
        case UP:
            nextY = y - 1;
            nextX = x;
            break;
        }

        // 이동 가능한지 체크
        if (CanGo(nextY, nextX))
        {
            y = nextY;
            x = nextX;
            num++;
        }
        else // 방향 전환
        {
            switch (dir)
            {
            case RIGHT:
                dir = DOWN;
                break;
            case DOWN:
                dir = LEFT;
                break;
            case LEFT:
                dir = UP;
                break;
            case UP:
                dir = RIGHT;
                break;
            }
        }
    }
}

int main()
{
    cin >> N;

    SetBoard();

    PrintBoard();

    return 0;
}