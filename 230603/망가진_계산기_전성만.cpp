#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int d, p;
    long long r = 1; 
    cin >> d >> p;
    queue<long long> q;
    q.push(1);
    map<pair<long long, int>, int> um;
    while (p-- && !q.empty())
    {
        int si = q.size();
        while(si--)
        {
            int c = q.front();
            q.pop();
            for (int i = 2; i <= 9; i++)
            {
                long long tNum = c * i;
                if (to_string(tNum).size() > d) continue;
                if (um[{tNum, p}]) continue;
                um[{tNum, p}] = 1;
                q.push(c * i);
            }
        }
    }
    if (q.empty()) 
    {
        cout << -1;
        return 0;
    }
    while (!q.empty())
    {
        long long curN = q.front();
        string str = to_string(curN);
        q.pop();
        if (str.size() > d) continue;
        r = max(r, curN);
    }
    cout << r;
    return 0;
}
