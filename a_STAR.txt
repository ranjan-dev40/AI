#include <bits/stdc++.h>
using namespace std;

bool present(int target, vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] == target)
            return 1;
    return 0;
}

vector<int> A_star(vector<int> &H, vector<vector<int>> &G)
{
    vector<int> path;
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> q;
    int min_cost = 9999999;

    q.push({H[0], {0}});
    while (!q.empty())
    {
        int cost = q.top().first;
        vector<int> p = q.top().second;
        q.pop();

        int curr = p[p.size() - 1];
        if (curr == H.size() - 1)
        {
            if (cost < min_cost)
            {
                min_cost = cost;
                path = p;
            }
            break;
        }
        cost -= H[curr];
        for (int i = 0; i < G[curr].size(); i++)
        {
            if (G[curr][i] && !present(i, p))
            {
                p.push_back(i);
                q.push({cost + G[curr][i] + H[i], p});
                p.pop_back();
            }
        }
    }
    return path;
}

int main()
{
    vector<int> H = {15, 13, 13, 12, 10, 9, 7, 6, 5, 0};

    vector<vector<int>> G = {
        {0, 6, 3, 1, 0, 0, 0, 0, 0, 0},
        {6, 0, 2, 6, 3, 4, 0, 0, 0, 0},
        {3, 2, 0, 0, 4, 5, 0, 0, 0, 0},
        {1, 6, 0, 0, 7, 8, 9, 0, 0, 0},
        {0, 3, 4, 7, 0, 6, 9, 9, 0, 0},
        {0, 4, 5, 8, 6, 0, 8, 9, 0, 0},
        {0, 0, 0, 9, 9, 8, 0, 11, 12, 14},
        {0, 0, 0, 0, 9, 9, 11, 0, 14, 15},
        {0, 0, 0, 0, 0, 0, 12, 14, 0, 0},
        {0, 0, 0, 0, 0, 0, 14, 15, 0, 0}};

    vector<int> ans = A_star(H, G);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
}