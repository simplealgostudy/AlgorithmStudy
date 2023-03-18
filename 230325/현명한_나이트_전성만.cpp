#include <bits/stdc++.h>
using namespace std;
int chk[501][501];
int pos[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int x, y; cin >> x >> y;
    queue<pair<int, int>> q;
    q.push({x, y});
    chk[x][y] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) 
        {
            int x_ = cur.first + pos[i][0];
            int y_ = cur.second + pos[i][1];
            if (x_ < 0 || x_ > n || y_ < 0 || y_ > n || 0 != chk[x_][y_]) continue;
            chk[x_][y_] = chk[cur.first][cur.second] + 1;
            q.push({x_, y_});
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        cout << chk[a][b] - 1 << ' ';
    }
    return 0;
}
