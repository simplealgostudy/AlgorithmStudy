#include <bits/stdc++.h>
using namespace std;
map<int, int> vum[4001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        vum[a][b] = 1;
        vum[b][a] = 1;
    }
    int res = 1e9;
    for (int f = 1; f <= n - 2; f++)
    {
        if (vum[f].size() < 1) continue;
        auto last = vum[f].end();
        last--;
        for (auto it = vum[f].begin(); it != last; it++)
        {
            auto nextit = it;
            nextit++;
            for (auto it2 = nextit; it2 != vum[f].end(); it2++)
            {
                if (vum[it->first].find(it2->first) != vum[it->first].end())
                {
                    int k = vum[f].size();
                    int t = vum[it->first].size();
                    int t2 = vum[it2->first].size();
                    res = min(res, k + t + t2 - 6);
                }
            }
        }
    }
    cout << (res == 1e9 ? -1 : res);
    return 0;
}
