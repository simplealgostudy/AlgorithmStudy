#include <bits/stdc++.h>
using namespace std;

#define MAX (int)5e4+1
vector<pair<int, int>> v[MAX];
int n, t, far = 0;
pair<int, int> ans = {1, 1e9};
bool chk[MAX];

void dfs(int idx, int sum, int cnt) 
{
    chk[idx] = 1;

    if (ans.first == cnt && ans.second > sum) 
    {
        ans.second = sum;
        far = idx;
    } 
    else if (ans.first < cnt) 
    {
        far = idx;
        ans = {cnt, sum};
    }

    for (int i = 0; i < v[idx].size(); ++i) 
    {
        if (!chk[v[idx][i].first]) 
        {
            dfs(v[idx][i].first, v[idx][i].second + sum, cnt + 1);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);

    cin >> n >> t;

    for (int i = 1; i < n; ++i) 
    {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }

    dfs(1, 0, 1);

    memset(chk, 0, sizeof(chk));
    ans = {1, 1e9};
    dfs(far, 0, 1);

    cout << (ans.second/t) + (ans.second % t ? 1 : 0);

    return 0;
}