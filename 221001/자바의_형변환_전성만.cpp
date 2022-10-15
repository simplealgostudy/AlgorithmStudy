#include <bits/stdc++.h>
using namespace std;
void dfs(unordered_map<string, vector<string>> &tree, string t, string a, string b, bool c, bool d, bool &p)
{
    if (a == t)
    {
        c = true;
    }
    if (b == t)
    {
        d = true;
    }
    if (c && d)
    {
        p = true;
        return;
    }
    for (auto it : tree[t])
    {
        dfs(tree, it, a, b, c, d, p);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    unordered_map<string, int> um;
    unordered_map<string, vector<string>> tree;
    vector<string> v;
    string a, b;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        tree[b].push_back(a);
        v.push_back(b);
        um[a]++;
    }
    string root = "";
    for (auto i : v)
    {
        if (um.find(i) == um.end())
        {
            root = i;
            break;
        }
    }
    bool chk = false;
    cin >> a >> b;
    dfs(tree, root, a, b, false, false, chk);
    cout << chk;
    return 0;
}
