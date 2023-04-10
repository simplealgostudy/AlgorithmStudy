#include <bits/stdc++.h>
using namespace std;

bool check(stack<pair<int, int>>& stk, vector<int>& v, int a = 0)
{
    int m = 0;
    int k = stk.top().first;
    while (!stk.empty() && stk.top().first > a)
    {
        m++;
        stk.pop();
        if (!stk.empty() && stk.top().first != k)
        {
            if (stk.top().first == k - 1)
            {
                v[stk.top().second] = m;
                m = 0;
                k = stk.top().first;
            }
            else
            {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> v(n, 0);
    stack<pair<int, int>> stk;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (i == 0 && a != 1) {
            cout << -1;
            return 0;
        }
        if (!stk.empty() && stk.top().first > a && ! check(stk, v, a))
        {
            cout << -1;
            return 0;
        }
        stk.push({a, i});
    }
    if (!stk.empty() && ! check(stk, v))
    {
        cout << -1;
        return 0;
    }
    for (auto i : v)
        cout << i << '\n';
    return 0;
}