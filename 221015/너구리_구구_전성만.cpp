#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    unordered_map<int, int> um[n+1];
    vector<bool> chk(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        um[a][b] = c;
        um[b][a] = c;
    }
    long long result = 0;
    queue<pair<int, long long>> q;
    chk[1] = 1;
    q.push({1, 0});
    while (! q.empty())
    {
        pair<int, long long> cur = q.front();
        q.pop();
        if (result < cur.second)
        {
            result = cur.second;
        }
        for (auto it = um[cur.first].begin(); it != um[cur.first].end(); it++)
        {
            if (!chk[it->first])
            {
                chk[it->first] = 1;
                q.push({it->first, cur.second + it->second});
            }
        }
    }
    cout << result;
    return 0;
}
