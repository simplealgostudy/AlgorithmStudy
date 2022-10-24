#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> v(1001);
map<char, pair<int ,int>> mch;
map<pair<int, int>, char> mp;

bool check(int y, int x)
{
    if (y < 0 || y >= n || x < 0 || x >= m || v[y][x] == '_')
        return false;
    return true;
}

void dfs(int y, int x)
{
    if (!check(y, x))
        return;
    pair<int, int> pii = mch[v[y][x]];
    int n_y = y + pii.first;
    int n_x = x + pii.second;
    v[y][x] = '_';
    dfs(n_y, n_x);
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pair<int, int> back_n = {y + it->first.first, x + it->first.second};
        if (!check(back_n.first, back_n.second) || v[back_n.first][back_n.second] != it->second)
            continue;        
        dfs(back_n.first, back_n.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    mch['D'] = {1, 0}; mch['U'] = {-1, 0}; mch['L'] = {0, -1}; mch['R'] = {0, 1};
    mp[{0, 1}] = 'L'; mp[{0, -1}] = 'R'; mp[{1, 0}] = 'U'; mp[{-1, 0}] = 'D';
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int safezone = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != '_')
            {
                ++safezone;
                dfs(i, j);
            }
        }
    }
    cout << safezone;
    return 0;
}
