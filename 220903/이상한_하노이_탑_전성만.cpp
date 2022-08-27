#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    stack<int> stk[3];
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        stk[1].push(r);
        m[r] = 1;
    }
    vector<pair<int, int>> res;
    int cur = n;
    while(cur >= 1)
    {
        int next = m[cur];
        while (!stk[next].empty() && stk[next].top() != cur)
        {
            if (next == 1)
            {
                stk[2].push(stk[next].top());
                m[stk[next].top()] = 2;
                stk[next].pop();
                res.push_back({1, 2});
            }
            else
            {
                stk[1].push(stk[next].top());
                m[stk[next].top()] = 1;
                stk[next].pop();
                res.push_back({2, 1});
            }
        }
        if (next == 1)
        {
            stk[next].pop();
            res.push_back({1, 3});
        }
        else
        {
            stk[next].pop();
            res.push_back({2, 3});
        }
       cur--;
    }
    cout << res.size() << '\n';
    for (auto p : res)
    {
        cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}
