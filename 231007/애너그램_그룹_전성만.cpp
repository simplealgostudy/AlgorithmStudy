#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str;
    map<vector<int>, map<string, int>> um;
    map<vector<int>, int> umCnt;
    map<pair<int, string>, map<string, int>> mSort;
    while(!cin.eof() && cin >> str)
    {
        vector<int> v(26,0);
        for (auto c : str)
        {
            v[c-'a']++;
        }
        um[v][str]++;
        umCnt[v]++;   
    }
    for (auto it = um.begin(); it != um.end(); it++)
    {
        vector<int> cur = it->first;
        int cnt = umCnt[cur];
        mSort[{-cnt, it->second.begin()->first}] = it->second;
    }
    int c = 0;
    for (auto it = mSort.begin(); it != mSort.end() && c < 5; it++, c++)
    {
        cout << "Group of size " << -(it->first.first) << ": ";
        for (auto j = it->second.begin(); j != it->second.end(); j++)
        {
            cout << j->first << ' ';
        }
        cout << ".\n";
    }
    return 0;
}
