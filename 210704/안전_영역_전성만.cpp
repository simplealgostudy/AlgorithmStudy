#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
vector<vector<int>> v(101, vector<int>(101, 0));
int i, j, k, max_value, n;
void dfs(int y, int x, vector<vector<int>> & chk) {
    for (int t = 0; t < 4; t++) {
        int y_ = y + POS[t][0], x_ = x + POS[t][1];
        if (y_ >= 0 && y_ < n && x_ >= 0 && x_ < n && v[y_][x_] > k && !chk[y_][x_]) {
            chk[y_][x_] = 1;
            dfs(y_, x_, chk);
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> v[i][j];
            max_value = max(max_value, v[i][j]);
        }
    }
    int res = 1;
    for (k = 1; k < max_value; k++) {
        vector<vector<int>> chk(n, vector<int>(n, 0));
        int res_tmp = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (v[i][j] > k && !chk[i][j]) {
                    chk[i][j] = 1;
                    dfs(i, j, chk);
                    ++res_tmp;
                }
            }
        }
        res = max(res, res_tmp);
    }
    cout << res;
    return 0;
}