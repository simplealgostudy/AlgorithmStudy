#include <bits/stdc++.h>
using namespace std;

vector<int> uni(200001, 0);
vector<vector<int>> v(200001);
vector<int> cyc(200001, 0);
vector<bool> vis(200001, 1);
vector<bool> visited(200001, 0);
int n, q; 
int allNum = 1;

void makeMerge(int idx)
{
    uni[idx] = allNum;
    for (auto it : v[idx])
    {
        if (vis[it] || visited[it]) continue;
        visited[it] = 1;
        uni[it] = allNum;
        makeMerge(it);
    }
}

void makeUnion()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) continue;
        makeMerge(i);
        allNum++;
    }
}
void findCycle()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (cyc[i] == 1)
        {
            vis[i] = 0;
            q.push(i);
        }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (auto it : v[cur])
        {
            if (vis[it] == 0) continue;
            cyc[it]--;
            if (cyc[it] == 1)
            {
                vis[it] = 0;
                q.push(it);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> q;
    vector<bool> che(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
        cyc[a]++;
        cyc[b]++;
    }
    findCycle();
    makeUnion();
    for (int i = 0; i < q; i++)
    {
        int u, v; cin >> u >> v;
        int tu = uni[u];
        int tv = uni[v];
        cout << (tu == tv ? 1 : 2) << '\n';
    }
    return 0;
}
