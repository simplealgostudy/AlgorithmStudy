#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int n, answer = 0; cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int l, h; cin >> l >> h;
        v.push_back({l, h});
    }
    sort(v.begin(), v.end());
    pair<int, int> front = v[0];
    for (int i = 1; i < n; ++i) {
        if (front.second < v[i].second) {
            answer += (v[i].first - front.first) * front.second;
            front = v[i];
        }
    }
    pair<int, int> back = v[n-1];
    for (int i = n - 2; i >= 0; --i) {
        if (back.second < v[i].second) {
            answer += (back.first - v[i].first) * back.second;
            back = v[i];
        }
    }
    answer += (back.first - front.first + 1) * back.second;
    cout << answer;
    return 0;
}
