#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
int parent[N];
void make(int v)
{
    parent[v] = v;
}

int find(int v)
{
    if (parent[v] == v)
    {
        return v;
    }
    return find(parent[v]);
}

void Union(int a, int b)
{
    int PA = find(a);
    int PB = find(b);
    if (a != b)
    {
        parent[PB] = PA;
    }
}

int main()
{
    int nodes, edges;
    cout << "Enter nodes and edges" << endl;
    cin >> nodes >> edges;
    vector<pair<int, pair<int, int>>> vectEdge;
    // weight,node1, node2
    for (int i = 0; i < edges; i++)
    {
        int node1, node2, wt;
        cout << "enter nodes and weight" << endl;
        cin >> node1 >> node2 >> wt;
        vectEdge.push_back({wt, {node1, node2}});
    }
    sort(vectEdge.begin(), vectEdge.end());

    for (int i = 1; i <= nodes; i++)
    {
        make(i);
    }

    int total = 0;

    for (auto &edge : vectEdge)
    {
        int wt = edge.first;
        int node1 = edge.second.first;
        int node2 = edge.second.second;
        if (find(node1) == find(node2))
        {
            continue;
        }
        Union(node1, node2);
        total = total + wt;
        cout << node1 << " -- wt(" << wt << ")-- " << node2 << endl;
    }

    return 0;
}