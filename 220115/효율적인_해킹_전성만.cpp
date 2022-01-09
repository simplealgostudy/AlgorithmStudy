#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v(10001);
bool chk[10001];
vector<int> ans;
int maxc = 0;
int cnt = 0;
void dfs(int idx) {
    chk[idx] = 1;
    for (auto i : v[idx]) {
        if (!chk[i]) {
            cnt++;
            dfs(i);
        }
    }
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        memset(chk, 0, sizeof(chk));
        cnt = 0;
        dfs(i);
        if (maxc < cnt) {
            ans.clear();
            ans.push_back(i);
            maxc = cnt;
        } else if (maxc == cnt) {
            ans.push_back(i);
        }
    }
    for (auto res : ans) {
        cout << res << ' ';
    }    
    return 0;
} 