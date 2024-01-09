#include<bits/stdc++.h>
#define ll long long 
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

ll neighborX[4] = {0,0,1,-1};
ll neighborY[4] = {1,-1,0,0};
ll n, m, ans = 0;
ll visited[1010][1010];
char A[1010][1010];

bool isValid(int y, int x)
{
  if(y < 0) return false;
  if(x < 0) return false;
  if(y >= n) return false;
  if(x >= m) return false;
  if(A[y][x] == '#') return false;
  return true;
}

void dfs(int y, int x) 
{
  visited[y][x] = 1;
  for(int i = 0 ; i < 4 ; i++) 
  {
    int newX = x + neighborX[i];
    int newY = y + neighborY[i];
    if(isValid(newY, newX)) 
    {
      if(!visited[newY][newX]) 
      {
        dfs(newY,newX);
      }
    }
  }
}

int main()
{
	init_code();
	
	cin >> n >> m;
    for(int i=0; i<n; i++) 
    {
      for(int j=0; j<m; j++) 
      {
        cin >> A[i][j];
        visited[i][j] = 0;
      }
    }
    for(int i=0; i<n; i++) 
    {
      for(int j=0; j<m; j++) 
      {
        if(A[i][j] == '.' && !visited[i][j]) 
        {
          dfs(i,j);
          ans++;
        }
      }
    }
    cout << ans << endl;
	return 0;
}