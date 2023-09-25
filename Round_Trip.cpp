#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
vector<int> adj[N];
bool visited[N];
int parent[N];
vector<int> route;

bool dfs(int u, int p)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (visited[v])
        {
            // We found a round trip, so backtrack to find the route
            int cur = u;
            while (cur != v)
            {
                route.push_back(cur);
                cur = parent[cur];
            }
            route.push_back(v);
            route.push_back(u);
            return true;
        }
        parent[v] = u;
        if (dfs(v, u))
            return true;
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, -1))
            {
                cout << route.size() << endl;
                for (int city : route)
                {
                    cout << city << " ";
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
