#include <bits/stdc++.h>
using namespace std;
const int N=1e5+8;
vector<int >adj[N];
vector<int>com;
bool visited[N];
void dfs(int s)
{
    visited[s]=true;
    //com.push_back(s);
    for(int v:adj[s])
    {
     if(visited[v])continue;
     dfs(v);
    }
}

int main()
{

    // Write your code here
     int n,e;
     cin>>n>>e;
     for(int i=0;i<e;i++)
     {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);

     }
     vector<int>ans;
     for(int i=1;i<=n;i++)
     {
        if(!visited[i])
      {
          dfs(i);
        ans.push_back(i);
      }
     }
     cout<<ans.size()-1<<endl;
     for(int i=0;i<ans.size()-1;i++)
     {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
     }
    return 0;
}
