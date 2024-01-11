#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define pb push_back
#define ppb pop_back
#define read(x) long long x; cin>>x;
using namespace std;
const int maxN = 1e5+1;

void init_code()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

bool flag;
ll n,m,a,b;
unordered_map<ll,vector<ll>> adj;
vector<ll> visited(maxN);
vector<ll> color(maxN);

void dfs(int src)
{
    for(auto nbr:adj[src])
    {
        if(visited[nbr] == 0)
        {
            color[nbr] = !color[src];
            visited[nbr] = 1;
            dfs(nbr);
        }
        else if(color[nbr] == color[src])
        {
            flag = false;
        }
    }
}

int main()
{
	init_code();
	
    cin >> n >> m;
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    flag = true;
    for(ll i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            dfs(i);
        }
    }
    if(!flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(ll i=1; i<=n; i++)
        {
            if(color[i] == 0)
            {
                color[i] = 2;
            }
            cout<<color[i]<<" ";
        }
    }
	return 0;
}