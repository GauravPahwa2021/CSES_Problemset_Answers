#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define pb push_back
#define ppb pop_back
#define read(x) long long x; cin>>x;
using namespace std;
const long long int maxN = 1e5+1;

void init_code()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

ll n,m,a,b,res;
bool flag = false;
// unordered_map<ll,vector<ll>> adj;
vector<ll> visited;
vector<ll> parent;
//vector<ll> ans;

void dfs(ll src,vector<vector<ll>>& adj,vector<ll>& visited,vector<ll>& parent)
{
    stack<ll> s;
    s.push(src);
    while(!s.empty())
    {
        ll u = s.top();
        s.pop();
        visited[u] = true;
        for(ll v : adj[u])
        {
            if(!visited[v])
            {
                parent[v] = u;
                s.push(v);
            }
            else
            {
                ll _end = u;
                ll _start = v;
                vector<ll> path;
                path.push_back(_start);
                path.push_back(_end);
                while(_end != _start && _end != -1)
                {
                    _end = parent[_end];
                    path.push_back(_end);
                }
                if(path[path.size() - 1] != -1 && path.size() > 3)
                {
                    cout << path.size() << endl;
                    for(ll u : path)
                    {
                        cout<<u<<" ";
                    }
                    cout<<endl;
                    flag = true;
                    return;
                }
            }
        }
    }
    cout<<endl;
}

int main()
{
	init_code();
	
    cin >> n >> m;
    vector<vector<ll>> adj(n + 1, vector<ll>());
    for(ll i=0; i<m; i++)
    {
        cin>>a>>b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    visited.resize(n+1,0);
    parent.resize(n+1,-1);
    for(ll i=1; i<=n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(i,adj,visited,parent);
        }
        if(flag)
        {
            break;
        }
    }
    if(!flag)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
	return 0;
}