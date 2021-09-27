#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    map<pair<int, int>, int> um;
    queue<pair<int, int>> q;
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        um[{a, b}] = 1;
    }
    int pos[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    int res = 0;
    while (!um.empty()) {
        q.push(um.begin()->first);
        int cnt = 0;
        while (!q.empty()) {
            ++cnt;
            pair<int, int> cur = q.front();
            q.pop();
            um.erase(cur);
            for (int i = 0; i < 4; ++i) {
                pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                if (um.find(next) != um.end()) {
                    q.push({next.first, next.second});
                    um.erase(next);
                }
            }
        }
        res = max(res, cnt);
    }
    cout << res;
    return 0;
}