#include <bits/stdc++.h>
using namespace std;

void iterative_deepening_DFS(vector<vector<int>> &graph, int start, int depth, vector<int> &visited)
{
    if (depth > 0)
    {
        visited[start] = 1;
        cout << start << " ";
        for (int i = 1; i < graph.size(); i++)
        {

            if (graph[start][i] == 1 && visited[i] == 0)
            {
                iterative_deepening_DFS(graph, i, depth - 1, visited);
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
    int max_depth = 4;
    for (int d = 1; d <= max_depth; d++)
    {
        vector<int> visited(graph.size(), 0);
        iterative_deepening_DFS(graph, 1, d, visited);
        cout << endl;
    }

    return 0;
}
