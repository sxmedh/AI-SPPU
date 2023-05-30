#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int visited[N];
int graph[N][N];
void dfsRecurrsive(int node, int vertices)
{
    for (int i = 0; i < vertices; i++)
    {
        if (visited[i] != 1 && graph[node][i])
        {
            visited[i] = 1;
            cout << i << " ";
            dfsRecurrsive(i, vertices);
        }
    }
}
void dfs(int node, int vertices)
{
    visited[node] = 1;
    cout << node << endl;
    for (int i = 0; i < vertices; i++)
    {
        dfsRecurrsive(node, vertices);
    }
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
    cout << "enter starting node" << endl;
    int starting;
    cin >> starting;
    dfs(starting, vertices);
}