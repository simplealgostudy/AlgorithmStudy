#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    priority_queue<pair<int, int>> pq;
    priority_queue<int> p;
    vector<int> res(n, 0);
    for (int i = 0; i < n; i++)
    {
        int k; cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a; cin >> a;
            pq.push({a, -i});
        }
    }
    for (int i = 0; i < m; i++)
    {
        int b; cin >> b;
        p.push(b);
    }
    while(!p.empty() && !pq.empty())
    {
        if (p.top() > pq.top().first)
        {
            p.pop();   
            continue;
        }
        else if (p.top() < pq.top().first)
        {
            pq.pop();
            continue;
        }
        res[-pq.top().second]++;
        pq.pop();
        p.pop();
    }
    for (auto i : res)
    {
        cout << i << ' ';
    }
    return 0;
}
