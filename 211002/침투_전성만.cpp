#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
string v[1001];
bool chk[1001][1001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int m, n; cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        if (v[0][i] == '0' && !chk[0][i]) {
            chk[0][i] = 1;
            queue<pair<int, int>> q;
            q.push({0, i});
            while (!q.empty()) {
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first == m - 1) {
                    cout << "YES";
                    return 0;
                }
                for (int j = 0; j < 4; ++j) {
                    pair<int, int> next = {cur.first + POS[j][0], cur.second + POS[j][1]};
                    if (next.first >= 0 && next.first < m && next.second >= 0 && next.second < n && !chk[next.first][next.second] && v[next.first][next.second] == '0') {
                        chk[next.first][next.second] = 1;
                        q.push(next);
                    }
                }
            }
        }
    }
    cout << "NO";
    return 0;    
}