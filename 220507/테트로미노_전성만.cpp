#include <bits/stdc++.h>
using namespace std;
int arr[501][501], chk[501][501], n, m, ans;
int pos[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
void dfs(pair<int, int> p, int value, int cnt, pair<int, int> back) {
    if (cnt == 4) {
        ans = max(ans, value);
        return;
    }
    if (cnt == 3 && p != back) {
        dfs(back, value, cnt, back);
    }
    for (int i = 0; i < 4; i++) {
        pair<int, int> next = {p.first+pos[i][0], p.second+pos[i][1]};
        if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || chk[next.first][next.second]) continue;
        chk[next.first][next.second] = 1;
        dfs(next, value + arr[next.first][next.second], cnt+1, p);
        chk[next.first][next.second] = 0;
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            chk[i][j] = 1;
            dfs({i, j}, arr[i][j], 1, {0, 0});
            chk[i][j] = 0;
        }
    }
    cout << ans;
    return 0;
}
