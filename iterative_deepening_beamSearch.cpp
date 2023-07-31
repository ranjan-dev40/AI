#include <bits/stdc++.h>
using namespace std;

void iterative_deepening_DFS(vector<vector<int>> &graph, int start, int depth, vector<int> &visited, int w)
{
    if (depth > 0)
    {
        visited[start] = 1;
        cout << start << " ";
        int x = w;
        for (int i = 1; i < graph.size(); i++)
        {

            if (graph[start][i] == 1 && visited[i] == 0 && x > 0)
            {
                x--;
                iterative_deepening_DFS(graph, i, depth - 1, visited, w);
            }
        }
    }
}

int main()
{

    vector<vector<int>> graph{{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                              {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};

    int max_depth = 3;
    int weight = 1;
    for (int d = 1; d <= max_depth; d++)
    {
        vector<int> visited(graph.size(), 0);
        iterative_deepening_DFS(graph, 1, d, visited, weight);
        cout << endl;
        weight++;
    }

    return 0;
}