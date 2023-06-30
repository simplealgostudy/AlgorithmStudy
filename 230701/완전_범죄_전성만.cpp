#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, s, d, f, b, k; cin >> n >> s >> d >> f >> b >> k;
    vector<bool> chk(n + 1, false);
    for (int i = 0; i < k; i++)
    {
        int x; cin >> x;
        chk[x] = 1;
    }
    queue<pair<int,int>> q;
    q.push({s, 0});
    chk[s] = 1;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        if (cur.first == d)
        {
            cout << cur.second;
            return 0;    
        }
        int next = cur.first + f;
        int back = cur.first - b;
        int nextCnt = cur.second + 1;
        if (next <= n && !chk[next]) 
        {
            chk[next] = 1;
            q.push({next, nextCnt});
        }
        if (back >= 0 && !chk[back])
        {
            chk[back] = 1;
            q.push({back, nextCnt});
        }
    }
    cout << "BUG FOUND";
    return 0;
}
