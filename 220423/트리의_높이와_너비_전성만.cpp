#include <bits/stdc++.h>
using namespace std;
constexpr int m = 10001;
int dist[m];
pair<int, int> mp[m];
pair<int, int> pii[m];
vector<vector<int>> v(m);
int dfs(int p) {
    int r = 1;
    if (v[p][0] != -1) {
        pii[p].first = dfs(v[p][0]);
        r += pii[p].first;
    }
    if (v[p][1] != -1) {
        pii[p].second = dfs(v[p][1]);
        r += pii[p].second;
    }
    return r;
}
void plu(int cnt, int p, int lsum) {
    dist[p] = pii[p].first + lsum;
    if (v[p][0] != -1) {
        plu(cnt + 1, v[p][0], lsum);
    }
    if (v[p][1] != -1) {
        plu(cnt + 1, v[p][1], lsum + pii[p].first + 1);
    }
    if (mp[cnt].first > dist[p]) mp[cnt].first = dist[p];
    if (mp[cnt].second < dist[p]) mp[cnt].second = dist[p];
}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n+1, 0);
    for (int i = 0; i < n; i++) {
        mp[i+1] = {INT_MAX, -1};
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(b);
        if (b != -1) {
            arr[b]++;
        }
        v[a].push_back(c);
        if (c != -1) {
            arr[c]++;
        }
    }
    int parent = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            parent = i;
            break;
        }
    }
    dfs(parent);
    plu(1, parent, 0);
    pair<int, int> answer = {0, 0};
    for (int i = 1; i <= n; i++) {
        if (mp[i].first == INT_MAX || mp[i].second == -1) break;
        if (answer.second < mp[i].second - mp[i].first + 1) {
            answer.second = mp[i].second - mp[i].first + 1;
            answer.first = i;
        }
    }
    cout << answer.first << ' ' << answer.second;
    return 0;
}
