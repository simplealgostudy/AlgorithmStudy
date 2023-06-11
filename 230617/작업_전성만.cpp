#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &vec, vector<bool>& chk, int idx, int& res)
{
    for (auto i : vec[idx])
    {
        if (chk[i]) continue;
        res++;
        chk[i] = true;
        dfs(vec, chk, i, res);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, x, res = 0; cin >> n >> m;
    vector<vector<int>> vec(n + 1);
    vector<bool> chk(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        vec[b].push_back(a);
    }
    cin >> x;
    dfs(vec, chk, x, res);
    cout << res;
    return 0;
}
