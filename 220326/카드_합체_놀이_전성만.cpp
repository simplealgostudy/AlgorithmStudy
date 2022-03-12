#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    priority_queue<long long> pq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pq.push(-a);
    }
    while(m--) {
        long long b = pq.top();
        pq.pop();
        b += pq.top();
        pq.pop();
        pq.push(b);
        pq.push(b);
    }
    long long ans = 0;
    while (!pq.empty()) {
        ans += -pq.top();
        pq.pop();
    }
    cout << ans;
    return 0;
}
