#include <bits/stdc++.h>
using namespace std;
bool arr[101][101];
bool chk[101][101];
int r, c, n, bottom = 0;
int pos[4][2] = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
vector<pair<int, int>> tmp;

void print() {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << (arr[i][j]?"x":".");
        }
        cout << "\n";
    }
}

bool check(int y, int x) {
    return (y >= 0 && y < r && x >= 0 && x < c && !chk[y][x] && arr[y][x]);
}

bool move() {
    for (auto t : tmp) {
        if (t.first+1 == r || (arr[t.first+1][t.second] == 1 && !chk[t.first+1][t.second])) {
            return false;
        }
    }
    vector<pair<int,int>> tt = tmp;
    tmp.clear();
    for (auto t : tt) {
        chk[t.first][t.second] = 0;
        arr[t.first][t.second] = 0;
        tmp.push_back({t.first+1, t.second});
    }
    for (auto t : tmp) {
        chk[t.first][t.second] = 1;
        arr[t.first][t.second] = 1;
    }
    return true;
}

void dfs(int y, int x) {
    bottom = max(bottom, y);
    for (int i = 0; i < 4; ++i) {
        int dy = y + pos[i][0], dx = x + pos[i][1];
        if (check(dy, dx)) {
            chk[dy][dx] = 1;
            tmp.push_back({dy, dx});
            dfs(dy, dx);
        }
    }
}

void block(int idx, int left) {
    memset(chk, false, sizeof(chk));
    int i;
    if (!left) {
        for (i = 0; i < c, !arr[idx][i]; ++i);
    } else {
        for (i = c - 1; i >= 0, !arr[idx][i]; --i);
    }
    if (i >= 0 && i < c) {
        arr[idx][i] = 0;
        for (int j = 0; j < 4; ++j) {
            int dy = idx + pos[j][0], dx = i + pos[j][1];
            if (check(dy, dx)) {
                bool curchk = true;
                bottom = 0;
                chk[dy][dx] = 1;
                tmp.clear();
                tmp.push_back({dy, dx});
                memset(chk, false, sizeof(chk));
                dfs(dy, dx);
                if (bottom != r-1) {
                    while (curchk) {
                        curchk = move();
                    }
                }
            }
        }
    }
}

int main() {
    freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r ;++i) {
        string str; cin >> str;
        for (int j = 0; j < c; ++j) {
            arr[i][j] = (str[j]=='x'?1:0);
        }
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m; cin >> m; 
        block(r - m, i%2);
    }
    print();
    return 0;
}
