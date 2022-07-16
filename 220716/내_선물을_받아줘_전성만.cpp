#include <bits/stdc++.h>
using namespace std;
string str[1001];
bool chk[1001][1001];
unordered_map<char, pair<int, int>> pos;
int n, m, ans = 0;
pair<int, int> p[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int r, int c)
{
    int n_r = r + pos[str[r][c]].first;
    int n_c = c + pos[str[r][c]].second;
    if (!chk[n_r][n_c])
    {
        chk[n_r][n_c] = 1;
        dfs(n_r, n_c);
    }
    for (int i = 0; i < 4; i++)
    {
        n_r = r + p[i].first;
        n_c = c + p[i].second;
        if (n_r < 0 || n_r >= n || n_c < 0 || n_c >= m || chk[n_r][n_c]) continue;
        if ((0 == i && 'S' == str[n_r][n_c]) || (1 == i && 'N' == str[n_r][n_c]) || (2 == i && 'E' == str[n_r][n_c]) || (3 == i && 'W' == str[n_r][n_c]))
        {
            chk[n_r][n_c] = 1;
            dfs(n_r, n_c);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    pos['N'] = p[0];
    pos['S'] = p[1];
    pos['W'] = p[2];
    pos['E'] = p[3];
    for (int i = 0; i < n; i++) 
    {
        cin >> str[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!chk[i][j])
            {
                ans++;
                chk[i][j] = 1;
                dfs(i, j);
            }
        }
    }
    cout << ans;
    return 0;
}
