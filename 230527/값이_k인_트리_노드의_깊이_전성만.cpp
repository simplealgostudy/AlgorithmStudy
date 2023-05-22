#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& tree, int idx, vector<int> & v)
{
    for (auto i : tree[idx])
    {
        v[i] = v[idx] + 1;
        dfs(tree, i, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin>> n >> k;
    vector<int> v(n, 0);
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++)
    {
        int a, b; cin >> a >> b;
        tree[a].push_back(b);
    }
    dfs(tree, 0, v);
    for (int i = 0; i < n; i++)
    {
        int c; cin >> c;
        if (c == k)
        {
            cout << v[i];
        }
    }
    return 0;
}
