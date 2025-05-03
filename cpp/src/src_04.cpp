/* 연습문제 02: 가위바위보 */
#include <iostream>

using namespace std;

int main()
{
    srand(time(0));

    const int SCISSORS = 1;
    const int ROCK = 2;
    const int PAPER = 3;

    int wins = 0;
    int total = 0;

    while (true)
    {
        if (total == 0)
        {
            cout << "현재 승률: X" << endl;
        }
        else
        {
            // int winPercentage = wins / total * 100; // int / int -> int !!
            int winPercentage = (wins * 100) / total;
            cout << "현재 승률: " << winPercentage << endl;
        }
        cout << "가위(1) 바위(2) 보(3) 골라골라" << endl;
        cout << "> ";

        int pcValue = 1 + (rand() % 3); // 1 2 3

        int input;
        cin >> input;

        switch (input)
        {
        case SCISSORS:
            switch (pcValue)
            {
            case SCISSORS:
                cout << "가위(User) vs 가위(PC) : 무승부" << endl;
                break;
            case ROCK:
                cout << "가위(User) vs 바위(PC) : 패" << endl;
                total++;
                break;
            case PAPER:
                cout << "가위(User) vs 보(PC) : 승" << endl;
                total++;
                wins++;
                break;
            }
            break;
        case ROCK:
            switch (pcValue)
            {
            case SCISSORS:
                cout << "바위(User) vs 가위(PC) : 승" << endl;
                total++;
                wins++;
                break;
            case ROCK:
                cout << "바위(User) vs 바위(PC) : 무승부" << endl;
                break;
            case PAPER:
                cout << "바위(User) vs 보(PC) : 패" << endl;
                total++;
                break;
            }
            break;
        case PAPER:
            switch (pcValue)
            {
            case SCISSORS:
                cout << "보(User) vs 가위(PC) : 패" << endl;
                total++;
                break;
            case ROCK:
                cout << "보(User) vs 바위(PC) : 승" << endl;
                total++;
                wins++;
                break;
            case PAPER:
                cout << "보(User) vs 보(PC) : 무승부" << endl;
                break;
            }
            break;
        default:
            break;
        }
    }

    return 0;
}