#include <bits/stdc++.h>
using namespace std;
string arr[51];
int chk[64][51][51];
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node {
    int y, x, k;
};
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    queue<node> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '0') {
                q.push({i, j, 0});
                chk[0][i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        node cur = q.front();
        int time = chk[cur.k][cur.y][cur.x];
        q.pop();
        if (arr[cur.y][cur.x] == '1') {
            cout << chk[cur.k][cur.y][cur.x] - 1;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            pair<int, int> next = {cur.y + pos[i][0], cur.x + pos[i][1]};
            if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < m && arr[next.first][next.second] != '#') {
                char t = arr[next.first][next.second];
                if (t >= 'a' && t <= 'f') {
                    if (!chk[cur.k][next.first][next.second]) {
                        int nextkey = cur.k | (1 << (t - 'a'));
                        chk[nextkey][next.first][next.second] = time + 1;
                        q.push({next.first, next.second, nextkey});
                    }
                } else if (t >= 'A' && t <= 'F') {
                    if (cur.k & (1 << (t - 'A')) && (!chk[cur.k][next.first][next.second] || chk[cur.k][next.first][next.second] > time + 1)) {
                        chk[cur.k][next.first][next.second] = time + 1;
                        q.push({next.first, next.second, cur.k});
                    }
                } else if (!chk[cur.k][next.first][next.second]) {
                    chk[cur.k][next.first][next.second] = time + 1;
                    q.push({next.first, next.second, cur.k});
                }
            }
        }
    }
    cout << -1;
    return 0;
}
