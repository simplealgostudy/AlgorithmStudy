#include <bits/stdc++.h>
using namespace std;

void dfs(int c, int chk, vector<vector<int>> &v, vector<vector<int>> &color, long long &ans1, long long &ans2)
{
    ans1 += color[c][chk];
    ans2 += color[c][!chk];
    chk ^= 1;
    for (auto i : v[c])
    {
        dfs(i, chk, v, color, ans1, ans2);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> v(n);
    vector<vector<int>> color(n);
    for (int i = 1; i < n; i++)
    {
        int p, c; cin >> p >> c;
        v[p].push_back(c);
    }
    for (int i = 0; i < n; i++)
    {
        int w, b; cin >> w >> b;
        color[i].push_back(w);
        color[i].push_back(b);
    }
    long long ans1 = 0, ans2 = 0;
    dfs(0, 0, v, color, ans1, ans2);
    cout << min(ans1, ans2);
    return 0;
}
