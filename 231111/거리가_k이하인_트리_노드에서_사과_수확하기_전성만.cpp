#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, answer = 0;
    cin >> n >> k;
    vector<int> v(n + 1, 0), chk(n + 1, 0);
    unordered_map<int, vector<int>> um;
    queue<pair<int,int>> q;
    for (int i = 0; i < n - 1; i++)
    {
        int p, c;
        cin >> p >> c;
        um[p].push_back(c);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    q.push({0, 0});
    chk[0] = 1;
    if (v[0]) answer++;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.second + 1 > k) continue;
        for (auto it : um[cur.first])
        {
            if (chk[it]) continue;
            chk[it] = 1;
            if (v[it]) answer++;
            q.push({it, cur.second + 1});
        }
    }
    cout << answer;
    return 0;
}
