#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = LONG_MAX;
vector<vector<int>> v;
void dfs(int idx, long long val, int s, int b)
{
    ans = min(ans, val);
    for (int i = idx + 1; i < n; i++)
    {
        int ns = s * v[i][0];
        int nb = b + v[i][1];
        dfs(i, abs(ns-nb), ns, nb);
    }
}
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, b; cin >> s >> b;
        v.push_back({s, b});
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, abs(v[i][0]-v[i][1]), v[i][0], v[i][1]);
    }
    cout << ans;
    return 0;
}
