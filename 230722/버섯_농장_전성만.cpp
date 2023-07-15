#include <bits/stdc++.h>
using namespace std;

int dfs(int y, int x, vector<vector<int>> &v, vector<vector<bool>> &chk)
{
    if (y < 0 || y >= v.size() || x < 0 || x >= v.size() || 1 == v[y][x] || 1 == chk[y][x]) return 0;
    chk[y][x] = 1;
    return 1+dfs(y+1,x,v,chk)+dfs(y,x+1,v,chk)+dfs(y-1,x,v,chk)+dfs(y,x-1,v,chk);
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> v(n, vector<int>(n, 0));
    vector<vector<bool>> chk(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<int> seed;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (1 == v[i][j] || true == chk[i][j]) continue;
            seed.push_back(dfs(i, j, v, chk));
        }
    }
    if (0 == seed.size()) 
    {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for (auto s : seed)
    {
        int t = s / k;
        t += (s % k ? 1 : 0);
        m -= t;
        if (m < 0) 
        {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    cout << "POSSIBLE\n" << m;
    return 0;
}
