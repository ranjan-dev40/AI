#include <bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
using namespace std;


bool isWinning(vector<int> &positions)
{
    vector<int> mp = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    vector<int> revmp = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};

    vector<int> compPos, userPos;

    for (int i = 1; i <= 9; i++)
    {
        if (positions[i] == 5)
        {
            compPos.push_back(mp[i]);
        }
        else if (positions[i] == 3)
        {
            userPos.push_back(mp[i]);
        }
    }

    for (int i = 0; i < compPos.size(); i++)
    {
        for (int j = i + 1; j < compPos.size(); j++)
        {
            for (int k = j + 1; k < compPos.size(); k++)
            {
                int x = 15 - compPos[i] - compPos[j] - compPos[k];
                if (x == 0)
                {
                    return true;
                }
            }
        }
    }

    for (int i = 0; i < userPos.size(); i++)
    {
        for (int j = i + 1; j < userPos.size(); j++)
        {
            for (int k = j + 1; k < userPos.size(); k++)
            {
                int x = 15 - userPos[i] - userPos[j] - userPos[k];
                if (x == 0)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

char giveOX(int a)
{
    if (a == 3)
    {
        return 'X';
    }
    if (a == 5)
    {
        return 'O';
    }

    return ' ';
}

void display(vector<int> &positions)
{
    for (int i = 1; i <= 3; i++)
    {
        cout << giveOX(positions[i]) << " ";
        if (i != 3)
        {
            cout << "| ";
        }
    }
    cout << "\n----------\n";

    for (int i = 4; i <= 6; i++)
    {
        cout << giveOX(positions[i]) << " ";
        if (i != 6)
        {
            cout << "| ";
        }
    }
    cout << "\n----------\n";

    for (int i = 7; i <= 9; i++)
    {
        cout << giveOX(positions[i]) << " ";
        if (i != 9)
        {
            cout << "| ";
        }
    }
    cout << "\n";
}

void Go(vector<int> &positions, int pos, int turn)
{
    if (turn % 2 == 0) 
    {
        positions[pos] = 5;
    }
    else 
    {
        positions[pos] = 3;
    }
}

int Make2(vector<int> &positions)
{
    int pos;

    if (positions[5] == 2)
    {
        pos = 5;
    }
    else
    {
        bool done = false;

        for (int i = 2; i <= 8; i += 2)
        {
            if (positions[i] == 2)
            {
                pos = i;
                done = true;
                break;
            }
        }

        if (!done)
        {
            for (int i = 1; i <= 9; i += 2)
            {
                if (positions[i] == 2)
                {
                    pos = i;
                    break;
                }
            }
        }
    }

    return pos;
}

int PosWinOptimized(vector<int> &positions, int turn)
{
    vector<int> mp = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
    vector<int> revmp = {0, 4, 9, 2, 3, 5, 7, 8, 1, 6};

    if (turn % 2 == 0)
    {
        vector<int> compPos, userPos;

        for (int i = 1; i <= 9; i++)
        {
            if (positions[i] == 5)
            {
                compPos.push_back(mp[i]);
            }
            else if (positions[i] == 3)
            {
                userPos.push_back(mp[i]);
            }
        }

        for (int i = 0; i < compPos.size(); i++)
        {
            for (int j = i + 1; j < compPos.size(); j++)
            {
                int x = 15 - compPos[i] - compPos[j];
                if (x > 0 && x < 10 && positions[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }

        for (int i = 0; i < userPos.size(); i++)
        {
            for (int j = i + 1; j < userPos.size(); j++)
            {
                int x = 15 - userPos[i] - userPos[j];
                if (x > 0 && positions[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }
    }
    else
    {
        vector<int> compPos, userPos;
        for (int i = 1; i <= 9; i++)
        {
            if (positions[i] == 3)
            {
                compPos.push_back(mp[i]);
            }
            else if (positions[i] == 5)
            {
                userPos.push_back(mp[i]);
            }
        }

        for (int i = 0; i < compPos.size(); i++)
        {
            for (int j = i + 1; j < compPos.size(); j++)
            {
                int x = 15 - compPos[i] - compPos[j];
                if (x > 0 && x < 10 && positions[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }

        for (int i = 0; i < userPos.size(); i++)
        {
            for (int j = i + 1; j < userPos.size(); j++)
            {
                int x = 15 - userPos[i] - userPos[j];
                if (x > 0 && positions[revmp[x]] == 2)
                {
                    return revmp[x];
                }
            }
        }
    }

    return -1;
}

void PLAY()
{
    vector<int> positions(10, 2);

    cout << "Tic Tac Toe - The Game\n";
    cout << "First turn or Second Turn?\nEnter 1 for first turn, 2 for second turn\n";
    char x;
    x = getch();
    int turn;
    if (x == '1')
    {
        turn = 2;
    }
    else
    {
        turn = 1;
    }

    system("clear");

    cout << "1 | 2 | 3\n";
    cout << "----------\n";
    cout << "4 | 5 | 6\n";
    cout << "----------\n";
    cout << "7 | 8 | 9\n";
    cout << "\n The above are the Positions Of individual boxes.\nPress any key to continue\n";
    getch();
    system("clear");

    vector<int> TMP;
    display(positions);
    if (turn == 2)
    {
        cout << "Input position: \n";
        int x;
        char C;
        C = getch();
        x = C - 48;
        Go(positions, x, 1);
        system("clear");
        display(positions);
    }

    while (turn <= 9)
    {
        cout << "Computer is thinking....\n";
        sleep(1);
        switch (turn)
        {
        case 1:
            Go(positions, 1, turn);
            break;

        case 2:
            if (positions[5] == 2)
            {
                Go(positions, 5, turn);
            }
            else
            {
                Go(positions, 1, turn);
            }
            break;

        case 3:
            if (positions[9] == 2)
            {
                Go(positions, 9, turn);
            }
            else
            {
                Go(positions, 3, turn);
            }
            break;

        case 4:
            if (PosWinOptimized(positions, turn) != -1)
            {
                Go(positions, PosWinOptimized(positions, turn), turn);
            }
            else
            {
                if ((positions[1] == 3 || positions[4] == 3) && positions[8] == 3)
                {
                    Go(positions, 9, turn);
                }
                else if ((positions[3] == 3 || positions[6] == 3) && positions[8] == 3)
                {
                    Go(positions, 7, turn);
                }
                else if (positions[5] == 3 && positions[9] == 3)
                {
                    Go(positions, 7, turn);
                }
                else if ((positions[4] == 3 || positions[6] == 3) && positions[2] == 3)
                {
                    Go(positions, 1, turn);
                }
                else
                {
                    Go(positions, Make2(positions), turn);
                }
            }
            break;
        case 5:
            if (PosWinOptimized(positions, turn) != -1)
            {
                Go(positions, PosWinOptimized(positions, turn), turn);
            }
            else
            {
                if (positions[7] == 2)
                {
                    Go(positions, 7, turn);
                }
                else
                {
                    Go(positions, 3, turn);
                }
            }
            break;

        case 6:
            if (PosWinOptimized(positions, turn) != -1)
            {
                Go(positions, PosWinOptimized(positions, turn), turn);
            }
            else
            {
                Go(positions, Make2(positions), turn);
            }
            break;

        case 7:
            if (PosWinOptimized(positions, turn) != -1)
            {
                Go(positions, PosWinOptimized(positions, turn), turn);
            }
            else
            {
                Go(positions, Make2(positions), turn);
            }
            break;

        case 8:
            if (PosWinOptimized(positions, turn) != -1)
            {
                Go(positions, PosWinOptimized(positions, turn), turn);
            }
            else
            {
                Go(positions, Make2(positions), turn);
            }
            break;

        case 9:
            if (PosWinOptimized(positions, turn) != -1)
            {
                Go(positions, PosWinOptimized(positions, turn), turn);
            }
            else
            {
                Go(positions, Make2(positions), turn);
            }
            break;
        }

        system("clear");
        display(positions);

        if (isWinning(positions))
        {
            cout << "\nComputer Won!\n";
            break;
        }

        if (turn != 9)
        {
            cout << "Enter your move: ";
            int x;
            char C;
            C = getch();
            x = C - 48;

            while (positions[x] != 2)
            {
                cout << "Enter valid position ; ";
                C = getch();
                cout << "\n";
                x = C - 48;
            }
            Go(positions, x, turn + 1);
            system("clear");
            display(positions);

            if (isWinning(positions))
            {
                cout << "\nYou Won!\n";
                break;
            }
        }

        turn += 2;
    }

    if (turn > 9)
    {
        cout << "Game Draw!\n";
    }

    sleep(5);
    system("clear");
}

int main()
{
    while (true)
    {
        cout << "Start The Game? \nPress y or n\n";
        char x;
        x = getch();
        if (x == 'y')
        {
            system("clear");
            PLAY();
        }
        else
        {
            break;
        }
    }

    return 0;
}