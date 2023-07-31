#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
        cout << "Queue is FUll" << endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct Node *t;
    if (front == NULL)
        cout << "Queue is Empty" << endl;
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}
int isEmpty() { return front == NULL; }

void BFS(int G[][7], int start, int n)
{
    int i = start;
    int visited[7] = {0};

    cout << i << " ";
    visited[i] = 1;
    enqueue(i);

    while (!isEmpty())
    {
        i = dequeue();
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};

    if (visited[start] == 0)
    {
        int j;
        cout << start << " ";

        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
                DFS(G, j, n);
        }
    }
}

int main()
{
    int start, n = 7;
    char choice;
    cout << "Enter the starting node " << endl;
    cin >> start;
    int G[7][7] = {{0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 0, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0},
                   {0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0}};

    cout << "Enter your choice A for BFS and B for DFS " << endl;
    cin >> choice;
    switch (choice)
    {
    case 'A':
        cout << "BFS is called" << endl;
        BFS(G, start, n);
        break;
    case 'B':
        cout << "DFS is called" << endl;
        DFS(G, start, n);
        break;

    default:
        cout << "Don't know what to do ";
        DFS(G, start, n);
        break;
    }

    return 0;
}
