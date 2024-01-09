#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define pb push_back
#define ppb pop_back
#define read(x) long long x; cin>>x;
using namespace std;

void init_code()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

void dfs(unordered_map<ll,vector<ll>>& adj,vector<ll>& visited,int src)
{
    visited[src] = 1;
    for(auto nbr:adj[src])
    {
        if(visited[nbr] == 0)
        {
            dfs(adj,visited,nbr);
        }
    }
}

int main()
{
	init_code();
	
	ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edge(m,vector<ll>(2,0));
    for(ll i=0; i<m; i++)
    {
        for(ll j=0; j<2; j++)
        {
            cin>>edge[i][j];
        }
    }

    unordered_map<ll,vector<ll>> adj;
    for(ll i=0; i<m; i++)
    {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    vector<ll> visited(n+1,0);
    vector<ll> ans;
    ll res = 0;
    for(ll i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(adj,visited,i);
            res++;
            ans.push_back(i);
        }
    }
    cout<<(res-1)<<endl;
    ll len = ans.size();
    for(ll i=0; i<len-1; i++)
    {
        cout<<ans[i]<<" "<<ans[i+1]<<endl;
    }
	return 0;
}