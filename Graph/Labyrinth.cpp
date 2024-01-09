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

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
string step = "RLDU";

int main()
{
    init_code();
    int n, m;
    cin >> n >> m;
    pair<int, int> start, end;
    char grid[n][m];
    bool visited[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            visited[i][j] = false;
            if (grid[i][j] == 'A')
            {
                start = {i, j};
            }
            if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }

    visited[start.first][start.second] = true;
    int prevstep[n][m];

    queue<pair<int, int>> q;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int,int> v = make_pair(u.first + dx[i], u.second + dy[i]);
            if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m)
                continue;
            if (grid[v.first][v.second] == '#')
                continue;
            if (visited[v.first][v.second])
                continue;
            visited[v.first][v.second] = true;
            prevstep[v.first][v.second] = i;
            q.push(v);
        }
    }

    if (visited[end.first][end.second])
    {
        cout << "YES" << endl;
        vector<int> steps;
        while (end != start)
        {
            int p = prevstep[end.first][end.second];
            steps.push_back(p);
            end = make_pair(end.first - dx[p], end.second - dy[p]);
        }
        reverse(steps.begin(), steps.end());
        cout << steps.size() << endl;
        for (char ch : steps)
        {
            cout << step[ch];
        }
    }
    else
    {
        cout << "NO" << endl;
    }

	return 0;
}