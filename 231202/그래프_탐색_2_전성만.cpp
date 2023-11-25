#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>& v, int idx, int &n, unordered_map<int, vector<int>> &um, int ch = 0)
{
    queue<int> qu;
    qu.push(idx);
    vector<bool> chk(n + 1, 0);
    chk[ch] = 1;
    chk[idx] = 1;
    while (! qu.empty())
    {
        int cur = qu.front();
        qu.pop();
        for (auto it : um[cur])
        {
            if (chk[it] || (v[it] != -1 && v[it] <= v[cur])) continue;
            chk[it] = 1;
            v[it] = v[cur] + 1;
            qu.push(it);
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> v(n+1, -1);
    v[1] = 0;
    unordered_map<int, vector<int>> um;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        um[a].push_back(b);
        um[b].push_back(a);
    }
    bfs(v, 1, n, um);
    int q; cin >> q;
    for (int t = 0 ; t < q; t++)
    {
        int i, j; cin >> i >> j;
        um[i].push_back(j);
        um[j].push_back(i);
        if (v[i] != -1 && v[j] != -1 && v[j] < v[i])
        {
            swap(i, j);
        }
        else if (v[i] == -1 && v[j] != -1)
        {
            swap(i, j);
        }
        if (v[i] != v[j])
        {
            v[j] = v[i] + 1;
            bfs(v, j, n, um, i);
        }
        for (int c = 1; c <= n; c++)
        {
            cout << v[c] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
    