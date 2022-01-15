#include <bits/stdc++.h>
using namespace std;
bool chk[501][501];
const int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> chk[i][j];
        }
    }
    int cnt = 0, maxcnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (chk[i][j]) {
                cnt++;
                int si = 0;
                chk[i][j] = 0;
                queue<pair<int,int>> q;
                q.emplace(i, j);
                while (!q.empty()) {
                    pair<int, int> cur = q.front();
                    si++;
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        pair<int, int> next = {cur.first + pos[k][0], cur.second + pos[k][1]};
                        if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m && chk[next.first][next.second]) {
                            chk[next.first][next.second] = 0;
                            q.emplace(next);
                        }

                    }
                }
                maxcnt = max(maxcnt, si);
            }
        }
    }
    cout << cnt << '\n' << maxcnt;
    return 0;
}
