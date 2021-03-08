#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    map<string, int> m_;
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        m_[str] = 1;
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        string str; cin >> str;
        if (m_.find(str) != m_.end()) res++;
    }
    cout << res;
    return 0;
}