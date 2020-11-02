#include <bits/stdc++.h>
using namespace std;
int pos [4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char c[101][101];
void dfs(vector<vector<bool>> &chk, int x, int y, int n) {
    for(int i = 0; i < 4; i++) {
        int x_ = x + pos[i][0], y_ = y + pos[i][1];
        if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n && !chk[x_][y_] && c[x_][y_] == c[x][y]) {
            chk[x_][y_] = true;
            dfs (chk, x_, y_, n);
        }
    }
    if(c[x][y] == 'G') c[x][y] = 'R';
    return;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> c[i][j];
    for (int k = 0; k < 2; k++) {
        vector<vector<bool>> chk(n, vector<bool>(n, false));
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0;j < n; j++) {
                if(!chk[i][j]) {
                    res++;
                    chk[i][j] = true;
                    dfs(chk, i, j, n);
                }
            }
        }
        cout << res << ' ';
    }
    return 0;
}