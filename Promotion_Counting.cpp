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
const int mx=1e5;
int p[mx+5];
int n;
vector<int>adj[mx+5];
orderedSet<int>st[mx+5];
int ans[mx+5];
void dfs(int node)
{
    st[node].insert(p[node]);
    for(auto son:adj[node])
    {
        dfs(son);
        if(st[node].size()<st[son].size())
            st[node].swap(st[son]);
        for(auto i:st[son]) st[node].insert(i);
    }
    ans[node]=st[node].order_of_key(p[node]);
}
int32_t main()
{
     freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cin>>n;
     for(int i=1; i<=n; i++) cin>>p[i];
     for(int i=2; i<=n; i++)
     {
         int x;
         cin>>x;
         adj[x].pb(i);
     }
     dfs(1);

     for(int i=1; i<=n; i++) cout<<ans[i]<<endl;

}


