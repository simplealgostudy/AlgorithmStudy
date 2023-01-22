#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> cur, ne;
int chknum[501];
bool chk[501];
int res[501], dest[501];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        dest[i] = a;
        int b; cin >> b;
        int cnt = 0;
        while (-1 != b)
        {
            cur[i].push_back(b);
            ne[b].push_back(i);
            cin >> b;
        }
        if (0 == cur[i].size())
        {
            res[i] = a;
            q.push(i);
            chk[i] = 1;
        }
    }
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        int val = 0;
        bool curchk = 1;
        for (auto curval : cur[c])
        {
            val = max(val, res[curval]);
        }
        if (!curchk)
            continue;
        chk[c] = 1;
        res[c] = val + dest[c];
        for (auto nextval : ne[c])
        {
            chknum[nextval]++;
            if (chknum[nextval] == cur[nextval].size())
                q.push(nextval);
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << '\n';
    return 0;
}
