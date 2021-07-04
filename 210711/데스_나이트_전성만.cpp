#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, r1, c1, r2, c2; cin >> n >> r1 >> c1 >> r2 >> c2;
    vector<vector<bool>> v(n, vector<bool>(n, 0));
    v[r1][c1] = 1;
    struct th{
        int y, x, cnt;
    };
    queue<th> q;
    q.push({r1, c1, 0});
    int pos[6][2] = {{-2, -1}, {-2, 1}, {0, -2}, {0, 2}, {2, -1}, {2, 1}};
    while(!q.empty()) {
        th cur = q.front();
        if (cur.y == r2 && cur.x == c2) {
            cout << cur.cnt;
            return 0;
        }
        q.pop();
        for (int i = 0; i < 6; i++) {
            th next = {cur.y + pos[i][0], cur.x + pos[i][1], cur.cnt + 1};
            if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n && !v[next.y][next.x]) {
                v[next.y][next.x] = 1;
                q.push(next);
            }
        }
    }
    cout << -1;
    return 0;
}