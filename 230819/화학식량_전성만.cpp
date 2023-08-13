#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    // h = 1, c = 12, o = 16
    stack<int> stk;
    for (auto c : str)
    {
        if (c == '(')
        {
            stk.push(0);
        }
        else if (c == ')')
        {
            int t = 0;
            while (stk.top() != 0)
            {
                t += stk.top();
                stk.pop();
            }
            stk.pop();
            stk.push(t);
        }
        else if (c >= '2' && c <= '9')
        {
            if (stk.empty()) continue;
            int t = stk.top() * (c - '0');
            stk.pop();
            stk.push(t);
        }
        else if (c == 'H')
        {
            stk.push(1);
        }
        else if (c == 'C')
        {
            stk.push(12);
        }
        else if (c == 'O')
        {
            stk.push(16);
        }
    }
    int ans = 0;
    while(!stk.empty())
    {
        ans += stk.top();
        stk.pop();
    }
    cout << ans;
    return 0;
}
