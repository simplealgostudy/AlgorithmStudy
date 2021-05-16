#include <bits/stdc++.h>
using namespace std;

struct th 
{
    long long in, a, p;
};
th m[123457];

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n; 
    cin >> n;
    map<int, vector<int>> ma;

    for (int i = 2; i <= n; i++) 
    {
        char t;
        int a, p;
        cin >> t >> a >> p;
        ma[p].push_back(i);
        m[i].a = (t == 'S' ? a : -a);
        m[i].in = p;
        m[p].p++;
    }

    vector<int> end;
    for (int i = 2; i <= n; i++) 
    {
        if (m[i].p == 0) 
        {
            end.push_back(i);
        }
    }
    for (auto i : end) 
    {
        int t = i;
        while (t != 1) 
        {
            m[m[t].in].a += max((long long)0, m[t].a);
            if (m[t].a > 0) m[t].a = 0;
            m[m[t].in].p--;
            if (m[m[t].in].p > 0) break;
            t = m[t].in;
        }
    }

    cout << m[1].a;
    
    return 0;
}