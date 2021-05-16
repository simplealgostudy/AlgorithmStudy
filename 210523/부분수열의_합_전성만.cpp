#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> res;
    res.push_back(0);
    for (int i = 0; i < n; i++) {
        int vSize = res.size();
        for (int j = 0; j < vSize; j++) {
            res.push_back(res[j]+v[i]);
        }
    }
    int cnt = 0;
    for (int i = 1; i < res.size(); i++) if (res[i] == s) cnt++;
    cout << cnt;
    return 0;
}