#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, t; cin >> n >> k >> t;

    long long ans = t;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    v.push_back(1e9+1);
    int b = 0;
    stack<int> stk;
    for (int i = 0; i < n + 1 && k > 0; i++)
    {
        if (ans > v[i])
        {
            stk.push(b);
            b = v[i];
            continue;
        }
        k--;
        if (b < ans)
        {
            ans += b;
            b = v[i];
            continue;
        }
        while (b >= ans && false == stk.empty() && k > 0)
        {
            ans += stk.top();
            stk.pop();
            k--;
        }
        if (b >= ans)
            break;
        ans += b;
        b = v[i];
    }
    while (false == stk.empty() && k > 0)
    {
        ans += stk.top();
        k--;
        stk.pop();
    }
    cout << ans;
    return 0;
}
