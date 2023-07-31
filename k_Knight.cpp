#include <bits/stdc++.h>
#include <chrono>
using namespace std::chrono;
using namespace std;

int count = 0;
void print_board(vector<vector<int>> board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 0 || board[i][j] == 5)
            {
                cout << "_ ";
            }
            else if (board[i][j] == 2)
            {
                cout << "K ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

void attack(vector<vector<int>> &board, int i, int j) // positions under attack are marked by 5
{
    if ((i + 2) < board.size() && (j - 1) >= 0)
    {
        board[i + 2][j - 1] = 5;
    }
    if ((i - 2) >= 0 && (j - 1) >= 0)
    {
        board[i - 2][j - 1] = 5;
    }
    if ((i + 2) < board.size() && (j + 1) < board[0].size())
    {
        board[i + 2][j + 1] = 5;
    }
    if ((i - 2) >= 0 && (j + 1) < board[0].size())
    {
        board[i - 2][j + 1] = 5;
    }
    if ((i + 1) < board.size() && (j + 2) < board[0].size())
    {
        board[i + 1][j + 2] = 5;
    }
    if ((i - 1) >= 0 && (j + 2) < board[0].size())
    {
        board[i - 1][j + 2] = 5;
    }
    if ((i + 1) < board.size() && (j - 2) >= 0)
    {
        board[i + 1][j - 2] = 5;
    }
    if ((i - 1) >= 0 && (j - 2) >= 0)
    {
        board[i - 1][j - 2] = 5;
    }
}

vector<vector<int>> place(vector<vector<int>> board, int i, int j) // position occupied are marked by 2
{
    board[i][j] = 2;
    attack(board, i, j);
    return board;
}

bool can_place(vector<vector<int>> board, int i, int j) // Empty positions are marked by 0
{
    if (board[i][j] == 0)
        return true;
    else
        return false;
}

void k_knight(vector<vector<int>> board, int k, int st_i, int st_j)
{
    if (k == 0)
    {
        // print_board(board);
        ::count++;
    }
    else
    {
        for (int i = st_i; i < board.size(); i++)
        {
            for (int j = (i == st_i) ? st_j : 0; j < board[0].size(); j++)
            {
                if (can_place(board, i, j))
                {
                    vector<vector<int>> new_board = board;
                    new_board = place(new_board, i, j);
                    k_knight(new_board, k - 1, i, j);
                }
            }
        }
    }
}

int main()
{
    int m, n;
    cout << "Enter the size of the board (row column) :" << endl;
    cin >> m >> n;
    vector<int> row(n, 0);
    vector<vector<int>> board(m, row);
    cout << "Enter the number of knights to place on the board :" << endl;
    int k;
    cin >> k;
    auto start = high_resolution_clock::now();
    k_knight(board, k, 0, 0);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time is : " << duration.count() << " microseconds." << endl;
    cout << "Number of Solutions are : " << ::count << endl;
    return 0;
}