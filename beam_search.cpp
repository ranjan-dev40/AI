#include <bits/stdc++.h>
using namespace std;
void beam_search(vector<vector<int>> &graph, int start, int w)

{

    vector<int> visited(graph.size(), 0);
    vector<int> solution;
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    cout << "Beam Search Traversal For width"
         << " " << w << " "
         << ":" << endl;
    // cout << start << " ";
    while (!q.empty())
    {
        int weight = w;
        for (int j = 0; j < graph[0].size(); j++)
        {
            if (graph[q.front()][j] == 1 && visited[j] == 0 && weight > 0)
            {
                weight--;
                // cout << j << " ";
                q.push(j);
                visited[j] = 1;
            }
        }
        solution.push_back(q.front());
        q.pop();
    }
    for (auto x : solution)
    {
        cout << x << " ";
    }
}
int main()
{
    vector<vector<int>> graph_1{
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0}};

    vector<vector<int>> graph_2 = {
        {0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0}};

    cout << "For first graph " << endl;
    beam_search(graph_1, 4, 1);
    cout << endl;
    beam_search(graph_1, 4, 2);
    cout << endl;
    beam_search(graph_1, 4, 3);
    cout << endl;
    cout << "For second graph " << endl;
    beam_search(graph_2, 7, 1);
    cout << endl;
    beam_search(graph_2, 7, 2);
    cout << endl;
    beam_search(graph_2, 7, 3);

    return 0;
}
