#include <bits/stdc++.h>
using namespace std;
int mon[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
long long calMon(string str)
{
    int ans = 0;
    int m = (str[5]-'0')*10 + (str[6]-'0');
    ans += (mon[m-1] * 1440);
    ans += ((str[8]-'0')*10 + (str[9]-'0'))*1440;
    return ans;
}
long long calTime(string str)
{
    return (((str[0]-'0')*10+(str[1]-'0'))*60)+(str[3]-'0')*10+(str[4]-'0');
}
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, f;
    string l;
    map<string, long long> ans;
    cin >> n >> l >> f;
    long long timeTmp = ((l[0]-'0')*100+(l[1]-'0')*10+(l[2]-'0'))*1440+(((l[4]-'0')*10+(l[5]-'0'))*60)+(l[7]-'0')*10+(l[8]-'0');
    map<string, long long> um;
    for (int i = 0; i < n; i++)
    {
        string mon,time, p, name;
        cin >> mon >> time >> p >> name;
        long long monTime = calMon(mon) + calTime(time);
        if (um.find(p+name) == um.end())
        {
            um[p+name] = monTime;
            continue;
        }
        long long prevTime = um[p+name];
        long long curT = (monTime - prevTime - timeTmp);
        um.erase(p+name);
        if (curT <= 0) continue;
        ans[name] += (curT * f);
    }

    if (true == ans.empty())
        cout << -1;
    for (auto it = ans.begin(); it != ans.end(); it++)
        cout << it->first << ' ' << it->second << '\n';
    return 0;
}
