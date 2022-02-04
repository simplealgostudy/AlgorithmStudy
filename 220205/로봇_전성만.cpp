#include <bits/stdc++.h>
using namespace std;
int arr[101][101];
bool chk[101][101][4];
int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct th {
    int y, x, s, c;
};
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    th start, goal;
    int y1, x1, s1; cin >> y1 >> x1 >> s1;
    start = {y1-1, x1-1, s1-1, 0};
    cin >> y1 >> x1 >> s1;
    goal = {y1-1, x1-1, s1-1, 0};
    queue<th> q;
    q.push(start);
    chk[start.y][start.x][start.s] = 1;
    while (!q.empty()) {
        th cur = q.front();
        q.pop();
        if (cur.y == goal.y && cur.x == goal.x && cur.s == goal.s) {
            cout << cur.c;
            return 0;
        }
        for (int i = 1; i <= 3; i++) {
            th next = {cur.y + (pos[cur.s][0] * i), cur.x + (pos[cur.s][1] * i), cur.s, cur.c + 1};
            if (chk[next.y][next.x][next.s]) continue;
            if (next.y >= 0 && next.y < m && next.x >= 0 && next.x < n && !arr[next.y][next.x]) {
                chk[next.y][next.x][next.s] = 1;
                q.push(next);
            } else {
                break;
            }
        }
        if (cur.s == 0 || cur.s == 1) {
            if (!chk[cur.y][cur.x][2]) {
                chk[cur.y][cur.x][2] = 1;
                q.push({cur.y, cur.x, 2, cur.c + 1});
            }
            if (!chk[cur.y][cur.x][3]) {
                chk[cur.y][cur.x][3] = 1;
                q.push({cur.y, cur.x, 3, cur.c + 1});
            }
        } else {
            if (!chk[cur.y][cur.x][0]) {
                chk[cur.y][cur.x][0] = 1;
                q.push({cur.y, cur.x, 0, cur.c + 1});
            }
            if (!chk[cur.y][cur.x][1]) {
                chk[cur.y][cur.x][1] = 1;
                q.push({cur.y, cur.x, 1, cur.c + 1});
            }
        }
    }
    return 0;
}