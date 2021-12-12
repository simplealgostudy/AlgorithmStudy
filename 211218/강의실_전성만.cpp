#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int,int>> v;
    int end = 0;
    for (int i = 0; i < n; ++i) {
        int m, s, e; cin >> m >> s >> e;
        v.emplace_back(s, e);
    }
    sort(v.begin(), v.end());
    long long answer = 0;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        while(!pq.empty() && -(pq.top()) <= v[i].first) pq.pop();
        pq.push(-v[i].second);
        answer = max(answer, (long long)pq.size());
    }
    cout << answer;
    return 0;
}