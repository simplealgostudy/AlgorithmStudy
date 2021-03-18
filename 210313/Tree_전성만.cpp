#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(2, vector<int>(1001));
void post(int s, int e, int r) {
    for (int i = s; i < e; i++) {
        if (v[1][i] == v[0][r]) {
            post(s, i, r+1);
            post(i+1, e, r+1+i-s);
            cout << v[0][r] << ' ';
        }
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> v[i][j];
            }
        }
        post(0, n, 0);
        cout << '\n';
    }
    return 0;
}