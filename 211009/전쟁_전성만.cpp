#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
bool chk[101][101];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, pos[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }
    int w = 0, b = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!chk[i][j]) {
                chk[i][j] = 1;
                int cnt = 1;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (! q.empty()) {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int k = 0; k < 4; ++k) {
                        pair<int ,int> next = {cur.first + pos[k][0], cur.second + pos[k][1]};
                        if (next.first >= 0 && next.first < m && next.second >= 0 && next.second < n && !chk[next.first][next.second] && arr[i][j] == arr[next.first][next.second]) {
                            ++cnt;
                            chk[next.first][next.second] = 1;
                            q.emplace(next);
                        }
                    }
                }
                if (arr[i][j] == 'W') {
                    w += cnt * cnt;
                } else {
                    b += cnt * cnt;
                }
            }
        }
    }
    cout << w << ' ' << b;
    return 0;
}