#include <bits/stdc++.h>
using namespace std;
struct cmp {
    constexpr bool operator() (pair<int, int> const& a, pair<int,int> const& b) const noexcept {
        if (a.second != b.second) return a.second > b.second;
        else return a.first > b.first;
    }
};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int a, b, c; cin >> a >> b >> c;
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;
    vector<pair<int,int>> ji, sa;
    for (int i = 0; i < c; i++) {
        int t, m;
        char c;
        cin >> t >> c >> m;
        int time = t;
        if (c=='B') {
            if (!ji.empty() && ji.back().second > t) {
                time = ji.back().second;
            }
        } else {
            if (!sa.empty() && sa.back().second > t) {
                time = sa.back().second;
            }                
        }
        for (int j = 0; j < m; j++) {
            if (c == 'B') {
                ji.push_back({time, time+a});
                time += a;
            } else {
                sa.push_back({time, time+b});
                time += b;
            }
        }
    }
    for (int i = 0; i < ji.size(); i++) {
        pq.push({0, ji[i].first});
    }
    for (int i = 0; i < sa.size(); i++) {
        pq.push({1, sa[i].first});
    }
    vector<int> blue, red;
    int cnt = 1;
    while(!pq.empty()) {
        if (pq.top().first == 0) {
            blue.push_back(cnt++);
        } else {
            red.push_back(cnt++);
        }
        pq.pop();
    }
    cout << blue.size() << '\n';
    for (int i = 0; i < blue.size(); i++) cout << blue[i] << ' ';
    cout << '\n' << red.size() << '\n';
    for (int i = 0; i < red.size(); i++) cout << red[i] << ' ';
    return 0;
}
