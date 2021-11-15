#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, w, l; cin >> n >> w >> l;
    queue<int> truck;
    queue<pair<int, int>> q;
    while(n--) {
        int t; cin >> t;
        truck.push(t);
    }
    int idx = 0, weight = 0;
    while (truck.size() || q.size()) {
        if (!q.empty() && q.front().second + w == idx) {
            weight -= q.front().first;
            q.pop();
        }
        if (!truck.empty() && q.size() < w && (weight + truck.front()) <= l) {
            weight += truck.front();
            q.push({truck.front(), idx});
            truck.pop();
        }
        idx++;
    }
    cout << idx;
    return 0;
}
