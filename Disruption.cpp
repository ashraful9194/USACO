#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, greater<T>,rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
const int mx=50000;
int n,m;
vector<pii>adj[mx+5];
set<pair<int,pii>>st[mx+6];
vector<pair<int,pii>>v[mx+6];
int ans[mx+5];
void dfs(int node,int par,int id)
{
    for(auto i:v[node])
        st[node].insert(i);
    for(auto i:adj[node])
    {
        int son=i.first;
        int idx=i.second;
        if(son==par) continue;
        dfs(son,node,idx);
       if(st[son].size()>st[node].size()) swap(st[son],st[node]);
       for(auto j:st[son])
       {
           if(st[node].count(j)) st[node].erase(j);
           else st[node].insert(j);
       }
    }
    ans[id]=st[node].empty()?-1:st[node].begin()->first;
}
int32_t main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     freopen("disrupt.in", "r", stdin);
     freopen("disrupt.out", "w", stdout);
     cin>>n>>m;
     for(int i=1; i<=n-1; i++)
     {
         int x,y;
         cin>>x>>y;
         adj[x].pb({y,i});
         adj[y].pb({x,i});
     }
     for(int i=0; i<m; i++)
     {
         int x,y,z;
         cin>>x>>y>>z;
         v[x].pb({z,{x,y}});
         v[y].pb({z,{x,y}});
     }
     dfs(1,0,0);
     for(int i=1; i<n; i++) cout<<ans[i]<<endl;
}
