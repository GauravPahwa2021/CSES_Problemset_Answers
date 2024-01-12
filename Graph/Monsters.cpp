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

ll n,m;
ll dx[4] = { 0, 0, -1, 1 }; 
ll dy[4] = { -1, 1, 0, 0 };
ll dist_M[1001][1001];
ll dist_A[1001][1001];
string step = "RLDU";
bool flag = false;

int main()
{
    init_code();
    
    cin >> n >> m;
    memset(dist_M,-1,sizeof(dist_M));
    memset(dist_A,-1,sizeof(dist_A));
    
    ll X,Y;
    char grid[n][m];
    queue<vector<ll>> q;
    for(ll i = 0; i < n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')
            {
                X = i;
                Y = j;
            }
            if(grid[i][j] == 'M')
            {
                q.push({i,j,0});
            }
        }
    }

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        ll x = u[0];
        ll y = u[1];
        ll steps = u[2];
        if(x < 0 || x >= n || y < 0 || y >= m)
        {
            continue;
        }
        if(grid[x][y] == '#')
        {
            continue;
        }
        if(dist_M[x][y] != -1)
        {
            continue;
        }
        dist_M[x][y] = steps;
        for(ll i = 0; i < 4; i++)
        {
            ll next_x = x + dx[i];
            ll next_y = y + dy[i];
            q.push({next_x,next_y,steps+1});
        }
    }

    while(!q.empty())
    {
        q.pop();
    }

    ll prevstep[n+1][m+1];
    memset(prevstep,0,sizeof(prevstep));

    q.push({X,Y,0,0});
    string ans;

    while(!q.empty())
    {
        auto u = q.front();
        q.pop();
        ll x = u[0];
        ll y = u[1];
        ll steps = u[2];
        ll dir = u[3];
        if(x < 0 || x >= n || y < 0 || y >= m)
        {
            continue;
        }
        if(grid[x][y] == '#')
        {
            continue;
        }
        if(dist_A[x][y] != -1)
        {
            continue;
        }
        if(dist_M[x][y]>=0 && dist_M[x][y]<=steps)
        {
            continue;
        }
        if(x == n-1 || x == 0 || y == m-1 || y == 0)
        {
            prevstep[x][y] = dir;
            while(x != X or y != Y) 
            {
                if(prevstep[x][y] == 0) 
                {
                    ans += 'L';
                    y++;
                }      
                else if(prevstep[x][y] == 1) 
                {
                    ans += 'R';
                    y--;
                }
                else if(prevstep[x][y] == 2)  
                {
                    ans += 'U';
                    x++;
                }
                else    
                {
                    ans += 'D';
                    x--;
                }    
            }
            reverse(ans.begin(), ans.end());
            flag = true;
            break;
        }
        dist_A[x][y] = steps;
        prevstep[x][y] = dir; 
        for(ll i = 0; i < 4; i++)
        {
            ll next_x = x + dx[i];
            ll next_y = y + dy[i];
            q.push({next_x,next_y,steps+1,i});
        }
    }

    if(flag)
    {
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

	return 0;
}