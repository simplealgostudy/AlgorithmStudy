#include <bits/stdc++.h>
using namespace std;
int arr[101];
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        pq.push(i);
    }
    map<int, int> ma;
    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        ma[i+1] = a;
    }
    int res = 0;
    queue<int> q;
    map<int, int> t;
    for (int i = 0; i < 2 * m; i++) {
        int a; cin >> a;
        if (a > 0) {
            if (!pq.empty()) {
                res += ma[a] * arr[pq.top()];
                t[a] = pq.top();
                pq.pop();
            } else {
                q.push(a);
            }
        } else {
            pq.push(t[-a]);
            if (!q.empty() && !pq.empty()) {
                res += ma[q.front()] * arr[pq.top()];
                t[q.front()] = pq.top();
                pq.pop();
                q.pop();
            }
        }
    }
    cout << res;
    return 0;
}