#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string n; 
    int k; 
    cin >> n >> k;
    int m = n.size();
    if (stoi(n) <= 10 || (stoi(n) < 100 && stoi(n) % 10 == 0)) {
        cout << -1 << '\n';
        return 0;
    }
    queue<string> q;
    q.emplace(n, 0);
    vector<int> res;
    for (int idx = 0; idx < k; ++idx) {
        set<string> setstr;
        int qsize = q.size();
        while (qsize--) {
            string tmp = q.front();
            q.pop();
            if (setstr.find(tmp) != setstr.end()) continue;
            setstr.insert(tmp);
            for (int i = 0; i < m - 1; ++i) {
                for (int j = i + 1; j < m; ++j) {
                    if (i == 0 && tmp[j] == '0') continue;
                    swap(tmp[i], tmp[j]);
                    q.push(tmp);
                    swap(tmp[i], tmp[j]);
                }
            }
        }
    }
    int ans = 0;
    while (!q.empty()) {
        ans = max(ans, stoi(q.front()));
        q.pop();
    }
    cout << ans;
    return 0;
}