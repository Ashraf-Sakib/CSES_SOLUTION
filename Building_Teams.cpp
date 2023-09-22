#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
vector<int> adj[N];
bool visited[N];
int color[N];

bool dfs(int u, int c)
{
    visited[u] = true;
    color[u] = c;

    for (int v : adj[u])
    {
        if (visited[v])
        {
            if (color[v] == color[u])
            {
                return false; // Not a bipartite graph
            }
        }
        else
        {
            if (!dfs(v, 3 - c))
            {
                return false; // Not a bipartite graph
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool isBipartite = true;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (!dfs(i, 1))
            {
                isBipartite = false;
                break;
            }
        }
    }

    if (!isBipartite)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << color[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
