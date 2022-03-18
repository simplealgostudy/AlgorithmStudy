#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int K, N;
    cin >> K >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> s;
    vector<int> v(K);
    for (int i = 0; i < K; i++) {
        cin >> v[i];
        s.insert(v[i]);
        pq.push(v[i]);
    }
    sort(v.begin(), v.end());
    long long m = v[K-1], cnt = pq.size();
    int tmp = N;
    while (N != 1) {
        long long cur = pq.top();
        pq.pop();
        for (auto i : v) {
            long long next = cur * i;
            if (next > INT_MAX) break;
            if (cnt >= tmp && next > m) break;
            if (s.find(next) == s.end()) {
                cnt++;
                s.insert(next);
                pq.push(next);
                m = max(next, m);
            }
        }
        N--;
    }
    cout << pq.top();
    return 0;
}
