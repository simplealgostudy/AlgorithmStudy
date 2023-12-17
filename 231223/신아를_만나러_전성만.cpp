#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int x, y, n; cin >> x >> y >> n;
    x += 500;
    y += 500;
    map<pair<int, int>, int> um;
    vector<vector<bool>> chk(1001,vector<bool>(1001, false));
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        um[{a+500,b+500}]=1;
    }
    chk[500][500] = 1;
    queue<pair<int, int>> q;
    q.push({500, 500});
    int ans = 0;
    int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while (!q.empty())
    {
        int si = q.size();
        while (si--)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == x && cur.second == y)
            {
                cout << ans;
                return 0;
            }
            for (int i = 0; i < 4; i++)
            {
                int x_ = cur.first + pos[i][0];
                int y_ = cur.second + pos[i][1];
                if (x_ < 0 || x_ > 1000 || y_ < 0 || y_ > 1000 || chk[x_][y_] || um[{x_, y_}]) continue;
                chk[x_][y_] = true;
                q.push({x_, y_});
            }
        }
        ans++;
    }
    return 0;
}
