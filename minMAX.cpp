#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class Board
{
    vector<int> board;
    vector<int> magicSquare;
    int computer;
    int depth;

public:
    Board(int computer, int depth)
    {
        board.resize(10, 0);
        magicSquare = {0, 8, 3, 4, 1, 5, 9, 6, 7, 2};
        this->computer = computer;
        this->depth = depth;
    }

    bool go(int pos, int player)
    {
        if (pos > 9 || pos < 1 || board[pos] != 0)
        {
            cout << "Invalid move" << endl;
            return false;
        }
        else
        {
            board[pos] = player;
            return true;
        }
    }

    void printBoard()
    {
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 0)
                cout << ".";
            else if (board[i] == 1)
                cout << "X";
            else
                cout << "O";
            if (i % 3 == 0)
                cout << endl;
            else
                cout << "|";
        }
        cout << endl;
    }

    bool movesLeft()
    {
        for (int i = 1; i <= 9; i++)
            if (board[i] == 0)
                return true;
        return false;
    }

    bool checkWin(int player)
    {
        vector<int> placed;
        for (int i = 1; i <= 9; i++)
            if (board[i] == player)
                placed.push_back(i);

        for (int i = 0; i < placed.size(); i++)
            for (int j = i + 1; j < placed.size(); j++)
                for (int k = j + 1; k < placed.size(); k++)
                    if (magicSquare[placed[i]] + magicSquare[placed[j]] + magicSquare[placed[k]] == 15)
                        return true;
        return false;
    }

    bool possWin(int player)
    {
        vector<int> placed;
        for (int i = 1; i <= 9; i++)
            if (board[i] == player)
                placed.push_back(i);

        for (int i = 0; i < placed.size(); i++)
            for (int j = i + 1; j < placed.size(); j++)
            {
                int temp = 15 - magicSquare[placed[i]] - magicSquare[placed[j]];
                if (temp >= 1 && temp <= 9)
                {
                    int idx = -1;
                    for (int k = 1; k <= 9; k++)
                        if (temp == magicSquare[k])
                        {
                            idx = k;
                            break;
                        }
                    if (board[idx] == 0)
                        return true;
                }
            }

        return false;
    }

    int rating(int player)
    {
        if (checkWin(player))
            return 10;
        else if (checkWin(3 - player))
            return -10;
        else if (possWin(3 - player))
            return -5;
        else if (possWin(player))
            return 5;
        else if (board[5] == player)
            return 3;
        else if (board[5] == 3 - player)
            return -3;
        else
        {
            int sum = 0;
            sum += (board[1] == player) + (board[3] == player) + (board[7] == player) + (board[9] == player);
            sum -= (board[1] == 3 - player) + (board[3] == 3 - player) + (board[7] == 3 - player) + (board[9] == 3 - player);
            return sum;
        }
    }

    int miniMax(int depth, int player)
    {
        int score = rating(player);
        cnt++;

        if (score == 10 || score == -10 || depth == 0 || !movesLeft())
            return score / (this->depth - depth == 0 ? 1 : this->depth - depth);
        int best = -99999;
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 0)
            {
                board[i] = player;
                int temp = -miniMax(depth - 1, 3 - player);
                if (temp > best)
                    best = temp;
                board[i] = 0;
            }
        }
        return best;
    }

    void computerMove()
    {
        int cnt = 0;
        int highestScore = -9999, bestMove = -1;
        for (int i = 1; i <= 9; i++)
        {
            if (board[i] == 0)
            {
                board[i] = computer;
                int score = -miniMax(depth - 1, 3 - computer);
                board[i] = 0;
                if (score > highestScore)
                {
                    highestScore = score;
                    bestMove = i;
                }
            }
        }
        go(bestMove, computer);
    }
};

int main()
{
    for (int depth = 1; depth <= 4; depth++)
    {
        cout << "Do you want to play first (Y/N)?" << endl;
        char choice;
        cin >> choice;
        Board game(choice == 'Y' ? 2 : 1, depth);
        int turn = choice == 'Y' ? 0 : 1;
        game.printBoard();
        while (true)
        {
            if (turn)
            {
                cout << "Computer's move" << endl;
                game.computerMove();
            }
            else
            {
                cout << "Your move" << endl;
                int pos;
                cin >> pos;
                game.go(pos, choice == 'Y' ? 1 : 2);
            }
            game.printBoard();
            turn = 1 - turn;
            if (game.checkWin(choice == 'Y' ? 1 : 2))
            {
                cout << "You win" << endl;
                break;
            }
            else if (game.checkWin(choice == 'Y' ? 2 : 1))
            {
                cout << "Computer wins" << endl;
                break;
            }
            else if (!game.movesLeft())
            {
                cout << "Draw" << endl;
                break;
            }
        }
    }
    cout << "Total number of recursion calls = " << cnt << endl;
}