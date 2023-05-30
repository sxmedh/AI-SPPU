#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 10;
const int INF = 10e6 + 10;
vector<pair<int, int>> g[N];
vector<int> dist(N, INF);
void dijkstra(int source)
{
    vector<int> vis(N, 0);

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    while (!st.empty())
    {
        auto node = *(st.begin());
        int v = node.second;
        int v_dist = node.first;
        st.erase(st.begin());
        if (vis[v])
        {
            continue;
        }
        vis[v] = 1;
        for (auto child : g[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (dist[v] + wt < dist[child_v])
            {
                dist[child_v] = dist[v] + wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++)
    {
        cout << "Enter nodes and edge weight: ";
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    // Call the dijkstra function with a source vertex
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    dijkstra(source);
    for (int i = 0; i < vertices; i++)
    {
        cout << "node " << i << " distance " << dist[i] << endl;
    }

    return 0;
}
