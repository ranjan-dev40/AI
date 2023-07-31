#include <bits/stdc++.h>
using namespace std;

vector<int> board(10, 2);
int X = 3, O = 5;

int possWin(char c)
{
    if (c == 'X')
    {
        int i = 1;
        while (i < 9)
        {
            if (board[i] * board[i + 1] * board[i + 2] == X * X * 2)
            {
                if (board[i] == 2)
                    return i;
                else if (board[i + 1] == 2)
                    return i + 1;
                else
                    return i + 2;
            }
            i += 3;
        }
        i = 1;
        while (i <= 10)
        {
            if (board[i] * board[i + 3] * board[i + 6] == X * X * 2)
            {
                if (board[i] == 2)
                    return i;
                else if (board[i + 3] == 2)
                    return i + 3;
                else
                    return i + 6;
            }
            i += 1;
        }
        if (board[1] * board[5] * board[9] == X * X * 2)
        {
            if (board[1] == 2)
                return 1;
            else if (board[5] == 2)
                return 5;
            else
                return 9;
        }
        if (board[3] * board[5] * board[7] == X * X * 2)
        {
            if (board[3] == 2)
                return 3;
            else if (board[5] == 2)
                return 5;
            else
                return 7;
        }
    }
    else if (c == 'O')
    {
        int i = 1;
        while (i < 9)
        {
            if (board[i] * board[i + 1] * board[i + 2] == O * O * 2)
            {
                if (board[i] == 2)
                    return i;
                else if (board[i + 1] == 2)
                    return i + 1;
                else
                    return i + 2;
            }
            i += 3;
        }
        i = 1;
        while (i <= 10)
        {
            if (board[i] * board[i + 3] * board[i + 6] == O * O * 2)
            {
                if (board[i] == 2)
                    return i;
                else if (board[i + 3] == 2)
                    return i + 3;
                else
                    return i + 6;
            }
            i += 1;
        }
        if (board[1] * board[5] * board[9] == O * O * 2)
        {
            if (board[1] == 2)
                return 1;
            else if (board[5] == 2)
                return 5;
            else
                return 9;
        }
        if (board[3] * board[5] * board[7] == O * O * 2)
        {
            if (board[3] == 2)
                return 3;
            else if (board[5] == 2)
                return 5;
            else
                return 7;
        }
    }
    return 0;
}

int make_2()
{
    if (board[5] == 2)
    {
        return 5;
    }
    else
    {
        for (int i = 2; i < 9; i += 2)
        {
            if (board[i] == 2)
            {
                return i;
            }
        }
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 2)
                return i;
        }
    }
    return 0;
}

void printBoard(int &choice)
{
    for (int i = 1; i < 10; i++)
    {
        if (board[i] == 2)
        {
            std::cout << "_ ";
        }
        else if (board[i] == X)
        {
            std::cout << "X ";
        }
        else if (board[i] == O)
        {
            std::cout << "O ";
        }
        if (i % 3 == 0)
        {
            std::cout << endl;
        }
    }
}

bool checkWin(char p)
{
    if (p == 'X')
    {

        int i = 1;
        while (i <= 7)
        {
            if (board[i] * board[i + 1] * board[i + 2] == X * X * X)
            {
                return true;
            }
            i += 3;
        }
        i = 1;
        while (i <= 3)
        {
            if (board[i] * board[i + 3] * board[i + 6] == X * X * X)
            {
                return true;
            }
            i += 1;
        }
        if (board[1] * board[5] * board[9] == X * X * X)
        {
            return true;
        }
        if (board[3] * board[5] * board[7] == X * X * X)
        {
            return true;
        }
        return false;
    }
    else if (p == 'O')
    {
        int i = 1;
        while (i <= 7)
        {
            if (board[i] * board[i + 1] * board[i + 2] == O * O * O)
            {
                return true;
            }
            i += 3;
        }
        i = 1;
        while (i <= 3)
        {
            if (board[i] * board[i + 3] * board[i + 6] == O * O * O)
            {
                return true;
            }
            i += 1;
        }
        if (board[1] * board[5] * board[9] == O * O * O)
        {
            return true;
        }
        if (board[3] * board[5] * board[7] == O * O * O)
        {
            return true;
        }
        return false;
    }
    return false;
}

void go(int n, int &turn, int &choice)
{
    if (turn % 2 == 1)
    {
        board[n] = X;
        turn++;
    }
    else
    {
        board[n] = O;
        turn++;
    }
}

void userMove(int &turn, int &choice)
{
    if (turn == 10)
        return;
    cout << "Enter your move : ";
    int x;
    cin >> x;
    int flag = 0;
    while (flag == 0)
    {
        if (board[x] != 2)
        {
            cout << "Invalid move !" << endl;
            cout << "Enter your move : ";
            cin >> x;
        }
        else
        {
            go(x, turn, choice);
            cout << endl;
            cout << endl;
            flag = 1;
        }
    }
}
void computerMove(int &turn, int &choice)
{
    switch (turn)
    {
    case 1:
        go(1, turn, choice);
        break;
    case 2:
        if (board[5] == 2)
            go(5, turn, choice);
        else
            go(1, turn, choice);
        break;
    case 3:
        if (board[9] == 2)
            go(9, turn, choice);
        else
            go(3, turn, choice);
        break;
    case 4:
        if (board[5] == X && board[9] == X)
        {
            go(3, turn, choice);
            return;
        }
        if (board[8] == X && board[6] == X)
        {
            go(9, turn, choice);
            return;
        }
        if (board[2] == X && board[6] == X)
        {
            go(3, turn, choice);
            return;
        }
        if (board[4] == X && board[8] == X)
        {
            go(7, turn, choice);
            return;
        }
        if (board[4] == X && board[2] == X)
        {
            go(1, turn, choice);
            return;
        }
        if (board[1] == X && board[8] == X)
        {
            go(7, turn, choice);
            return;
        }
        if (possWin('X'))
        {
            go(possWin('X'), turn, choice);
        }
        else
        {
            go(make_2(), turn, choice);
        }
        break;
    case 5:
        if (possWin('X'))
        {
            go(possWin('X'), turn, choice);
        }
        else if (possWin('O'))
        {
            go(possWin('O'), turn, choice);
        }
        else if (board[7] == 2)
        {
            go(board[7], turn, choice);
        }
        else
        {
            go(3, turn, choice);
        }
        break;
    case 6:
        if (board[2] == X && board[7] == X && board[6] == X)
        {
            go(3, turn, choice);
            return;
        }
        if (possWin('O'))
        {
            go(possWin('O'), turn, choice);
        }
        else if (possWin('X'))
        {
            go(possWin('X'), turn, choice);
        }
        else
        {
            go(make_2(), turn, choice);
        }
        break;
    case 7:
        if (possWin('X'))
        {
            go(possWin('X'), turn, choice);
        }
        else if (possWin('O'))
        {
            go(possWin('O'), turn, choice);
        }
        else
        {
            go(make_2(), turn, choice);
        }
        break;
    case 8:
        if (possWin('O'))
        {
            go(possWin('O'), turn, choice);
        }
        else if (possWin('X'))
        {
            go(possWin('X'), turn, choice);
        }
        else
        {
            go(make_2(), turn, choice);
        }
        break;
    case 9:
        if (possWin('X'))
        {
            go(possWin('X'), turn, choice);
        }
        else if (possWin('O'))
        {
            go(possWin('O'), turn, choice);
        }
        else
        {
            go(make_2(), turn, choice);
        }
        break;
    default:
        break;
    }
}

int main()
{
    int turn = 1;
    cout << "Enter 1 to start the game.\nEnter 2 for computer to start the game." << endl;
    int choice;
    cin >> choice;
    printBoard(choice);
    if (choice == 2)
    {
        swap(X, O);
    }
    if (choice == 1)
    {
        while (turn <= 9)
        {
            cout << endl;
            userMove(turn, choice);
            printBoard(choice);
            cout << endl;
            if (checkWin('X'))
            {
                cout << "You Win !" << endl;
                break;
            }
            computerMove(turn, choice);
            printBoard(choice);
            cout << endl;
            if (checkWin('O'))
            {
                cout << "You Lose !" << endl;
                break;
            }
        }
        if (turn == 10 && !checkWin('X') && !checkWin('O'))
        {
            cout << "Draw Match !" << endl;
        }
    }
    else if (choice == 2)
    {
        while (turn <= 9)
        {
            cout << endl;
            computerMove(turn, choice);
            printBoard(choice);
            cout << endl;
            if (checkWin('X'))
            {
                cout << "You Lose !" << endl;
                break;
            }
            userMove(turn, choice);
            printBoard(choice);
            cout << endl;
            if (checkWin('O'))
            {
                cout << "You Win !" << endl;
                break;
            }
        }
        if (turn == 10 && !checkWin('X') && !checkWin('O'))
        {
            cout << "Draw Match !" << endl;
        }
    }
    return 0;
}