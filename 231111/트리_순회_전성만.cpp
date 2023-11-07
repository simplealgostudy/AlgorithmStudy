#include <bits/stdc++.h>
using namespace std;

void dfs(int idx, int dept, vector<vector<int>> &v, int &ans, int &cnt)
{
    cnt++;
    if (v[idx][0] >= 0)
    {
        ans += 2;
        dfs(v[idx][0], dept + 1, v, ans, cnt);
    }
    cnt--;
    if (v[idx][1] >= 0)
    {
        ans += 2;
        dfs(v[idx][1], dept + 1, v, ans, cnt);
    }
    if (0 == cnt)
    {
        ans--;
    }
    return;
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> v(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int g, a, b; cin >> g >> a >> b;
        v[g - 1].push_back(a - 1);
        v[g - 1].push_back(b - 1);
    }
    int ans = 1;
    dfs(0, 0, v, ans, cnt);
    cout << ans;
    return 0;
}
