#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({-a, b});
    }
    priority_queue<int> pqans;
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (!pqans.empty() && pqans.size() == -cur.first && -pqans.top() < cur.second) {
            pqans.pop();
            pqans.push(-cur.second);
        } else if (pqans.size() < -cur.first) {
            pqans.push(-cur.second);
        }
    }
    long long res = 0;
    while (!pqans.empty()) {
        res += (-pqans.top());
        pqans.pop();
    }
    cout << res;
    return 0;
}
