#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    priority_queue<pair<int, int>> pre, level;
    for (int i = 0; i < k; i++)
    {
        int a, b; cin >> a >> b;
        level.push({-b, a});
    }
    int lev = 0;
    int sum = 0;
    while (! level.empty())
    {
        pair<int, int> cur = level.top();
        level.pop();
        lev = -cur.first;
        sum += cur.second;
        while (pre.size() == n)
        {
            sum += pre.top().first;
            pre.pop();
        }
        pre.push({-cur.second, cur.first});
        if (pre.size() == n && sum >= m)
        {
            cout << lev;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
