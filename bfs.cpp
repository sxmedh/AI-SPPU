#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int visited[MAX];
int graph[MAX][MAX];

void bfsRecursive(queue<int> &q, int vertices)
{
    if (q.empty())
    {
        return;
    }

    int current = q.front();
    q.pop();
    cout << current << " ";
    for (int i = 0; i < vertices; i++)
    {
        if (graph[current][i] == 1 && visited[i] != 1)
        {
            visited[i] = 1;
            q.push(i);
        }
    }
    bfsRecursive(q, vertices);
}

void bfs(int start, int vertices)
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    bfsRecursive(q, vertices);
}

int main()
{
    cout << "enter the number of vertices" << endl;
    int vertices;
    cin >> vertices;
    cout << "enter the number of edges" << endl;
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; i++)
    {
        cout << "enter the vertices connected" << endl;
        int node1, node2;
        cin >> node1 >> node2;
        graph[node1][node2] = 1;
        graph[node2][node1] = 1;
    }
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    int start;
    cout << "enter the starting node" << endl;
    cin >> start;
    bfs(start, vertices);
}
