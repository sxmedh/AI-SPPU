#include <bits/stdc++.h>
#define INF 9999999

using namespace std;
const int SI = 1000;
int G[SI][SI];
int main()
{
    int N;
    cout << "Enter the size of the graph: ";
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "Enter the weight " << i << " -> " << j << " of the graph: ";
            cin >> G[i][j];
        }
    }

    vector<bool> selected_node(N, false);

    selected_node[0] = true;
    int no_edge = 0;

    // printing for edge and weight
    cout << "Edge : Weight\n";
    while (no_edge < N - 1)
    {
        int minimum = INF;
        int a = 0;
        int b = 0;

        for (int m = 0; m < N; m++)
        {
            if (selected_node[m])
            {
                for (int n = 0; n < N; n++)
                {
                    if ((!selected_node[n]) && G[m][n])
                    {
                        // not in selected and there is an edge
                        if (minimum > G[m][n])
                        {
                            minimum = G[m][n];
                            a = m;
                            b = n;
                        }
                    }
                }
            }
        }

        cout << a << "-" << b << ":" << G[a][b] << endl;
        selected_node[b] = true;
        no_edge++;
    }
}