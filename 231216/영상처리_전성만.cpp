#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<double>> &v, vector<vector<bool>> &chk, int &t, int &y, int &x)
{
    int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    queue<pair<int, int>> q;
    int n = v.size();
    int m = v[0].size();
    q.push({y, x});
    while (false == q.empty())
    {
        int y_ = q.front().first;
        int x_ = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int n_y = y_+pos[i][0];
            int n_x = x_+pos[i][1];
            if (n_y < 0 || n_y >= n || n_x < 0 || n_x >= m || true == chk[n_y][n_x] || t > v[n_y][n_x]) continue;
            chk[n_y][n_x] = true;
            q.push({n_y,n_x});
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<vector<double>> v(n, vector<double>(m, 0));
    vector<vector<bool>> chk(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            double r, g, b; cin >> r >> g >> b;
            v[i][j] = (r+g+b) / 3;
        }
    }
    int t; cin >> t;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (false != chk[i][j] || v[i][j] < t) continue;
            ans++;
            bfs(v, chk, t, i, j);
        }
    }
    cout << ans;
    return 0;
}
