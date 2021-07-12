#include <bits/stdc++.h>
using namespace std;
int r, c, n;
const int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void print(vector<string> res) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << res[i][j];
        }
        cout << '\n';
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c >> n;
    vector<string> v(r);
    vector<vector<bool>> chk(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        cin >> v[i];
        for (int j = 0; j < c; j++) {
            if (v[i][j] == 'O') {
                chk[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    pair<int, int> cur = {i + pos[k][0], j + pos[k][1]};
                    if (cur.first >= 0 && cur.first < r && cur.second >= 0 && cur.second < c && !chk[cur.first][cur.second]) {
                        chk[cur.first][cur.second] = true;
                    }
                }
            }
        }
    }
    if (n == 1) {
        print(v);
        return 0;
    }
    if (!(n%2)) {
        string str(c, 'O');
        vector<string> res(r, str);
        print(res);
        return 0;
    }
    vector<vector<bool>> tmp(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (chk[i][j]) {
                v[i][j] = '.';
            } else {
                v[i][j] = 'O';
                tmp[i][j] = true;
                for (int k = 0; k < 4; k++) {
                    pair<int, int> cur = {i + pos[k][0], j + pos[k][1]};
                    if (cur.first >= 0 && cur.first < r && cur.second >= 0 && cur.second < c && !tmp[cur.first][cur.second]) {
                        tmp[cur.first][cur.second] = true;
                    }
                }
            }
        }
    }
    if (n % 4 == 3) print(v);
    else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (tmp[i][j]) {
                    v[i][j] = '.';
                } else {
                    v[i][j] = 'O';
                }
            }
        }
        print(v);    
    }
    return 0;
}