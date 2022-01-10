#include <bits/stdc++.h>
using namespace std;
const int pos[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};
bool chk[30][30];
double m[4];
double answer;
void dfs(int y, int x, int cnt, double ans) {
    if (!cnt) {
        answer += ans;
        return;
    }
    chk[y][x] = 1;
    for (int i = 0; i < 4; ++i) {
        int dy = y + pos[i][0], dx = x + pos[i][1];
        if (!chk[dy][dx]) {
            dfs(dy, dx, cnt - 1, ans * m[i]);
        }
    }
    chk[y][x] = 0;
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int cnt; cin >> cnt;
    for (int i = 0; i < 4; ++i) {
        cin >> m[i];
        m[i] /= 100;
    }
    dfs(cnt, cnt, cnt, 1);
    cout.precision(10);
    cout.fixed;
    cout << answer;
    return 0;
}
