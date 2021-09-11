#include <bits/stdc++.h>
using namespace std;
vector<int> vec[1001];
bool chk[1001];
int res = 0;
void dfs(int idx) {
    chk[idx] = 1;
    for (int i = 0; i < vec[idx].size(); ++i) {
        if (!chk[vec[idx][i]]) {
            dfs(vec[idx][i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!chk[i]) {
            res++;
            dfs(i);
        }
    }
    cout << res;
    return 0;
}