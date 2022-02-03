#include <bits/stdc++.h>
using namespace std;
#define MAX (int)1e6+1
bool chk[MAX];
bool chkc[MAX];
vector<pair<int, int>> v[MAX];
struct th {
    int v, dist, maxl;
};
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, f, s; cin >> n >> f >> s;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    queue<th> q;
    q.push({f, 0, 0});
    chk[f] = 1;
    int answer = 1e9;
    while (! q.empty()) {
        th cur = q.front();
        q.pop();
        if (cur.v == s) {
            answer = cur.dist - cur.maxl;
            break;
        }
        for (int i = 0; i < v[cur.v].size(); i++) {
            if (!chk[v[cur.v][i].first]) {
                chk[v[cur.v][i].first] = 1;
                q.push({v[cur.v][i].first, cur.dist + v[cur.v][i].second, max(cur.maxl, v[cur.v][i].second)});
            }
        }
    }
    cout << answer;
    return 0;
}
