#include <bits/stdc++.h>
using namespace std;
int n, m, h, len;
int answer = 4;
vector<pair<int, int>> permutation;
bool chk[32][12];
void per(int idx, int i) {
    bool cc = 1;
    for (int col = 1; col <= n; ++col) {
        int pos = col;
        for (int row = 1; row <= h; ++row) {
            if (chk[row][pos]) {
                pos++;
            } else if (chk[row][pos-1]) {
                pos--;
            }
        }
        if (pos != col) {
            cc = 0;
            break;
        }
    }
    if (cc) {
        answer = min(answer, idx);
    }
    if (answer <= idx || idx == 3) return;
    for (int cur = i; cur < len; cur++) {
        if (chk[permutation[cur].first][permutation[cur].second] || chk[permutation[cur].first][permutation[cur].second-1] || chk[permutation[cur].first][permutation[cur].second+1]) {
            continue;
        }
        chk[permutation[cur].first][permutation[cur].second] = 1;
        per(idx + 1, cur + 1);
        chk[permutation[cur].first][permutation[cur].second] = 0;
    }
    
}

int main(){
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> h;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        chk[a][b] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= h; ++j) {
            if (chk[j][i] || chk[j][i-1] || chk[j][i+1]) continue;
            permutation.push_back({j, i});
        }
    }
    len = permutation.size();
    per(0, 0);
    cout << (answer==4?-1:answer);
    return 0;
}
