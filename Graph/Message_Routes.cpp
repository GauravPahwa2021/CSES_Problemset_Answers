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
    vector<ll> parent(n+1,-1);

    queue<ll> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto nbr:adj[u])
        {
            if(visited[nbr] == 0)
            {
                q.push(nbr);
                visited[nbr] = 1;
                parent[nbr] = u;
            }
        }
    }
    vector<ll> ans;
    if(visited[n] == 1)
    {
        while(n != 1)
        {
            ans.push_back(n);
            n = parent[n];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        ll len = ans.size();
        cout<<len<<endl;
        for(ll i=0; i<len; i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    else
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
	return 0;
}