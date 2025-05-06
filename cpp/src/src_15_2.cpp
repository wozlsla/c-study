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
    RIGHT, // 0
    DOWN,  // 1
    LEFT,  // 2
    UP     // 3
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

    int dy[] = {0, 1, 0, -1};
    int dx[] = {1, 0, -1, 0};

    while (true)
    {
        board[y][x] = num; // 위치

        if (num == N * N) // 종결 조건
            break;

        // 이동 방향에 따른 다음 좌표 계산
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        // 이동 가능한지 체크
        if (CanGo(nextY, nextX))
        {
            y = nextY;
            x = nextX;
            num++;
        }
        else // 방향 전환
        {
            dir = (dir + 1) % 4;
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