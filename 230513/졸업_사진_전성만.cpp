#include <bits/stdc++.h>
using namespace std;

struct th
{
    string name;
    int e;
    int s;
};

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    unordered_map<string, string> name;
    map<string, vector<pair<int, int>>> place;
    for (int i = 0; i < n; i++)
    {
        vector<string> v;
        for (int j = 0; j < 4; j++)
        {
            string str; cin >> str;
            v.push_back(str);
        }
        if (name.find(v[0]) != name.end()) continue;
        name[v[0]] = v[1];
        int a = stoi(v[2]);
        int b = stoi(v[3]);
        place[v[1]].push_back({a, b - 1});
    }
    int biggerAns = 0;
    vector<th> ans;
    for (auto it = place.begin(); it != place.end(); it++)
    {
        vector<pair<int, int>> cur = it->second;
        if (biggerAns > cur.size()) continue;
        vector<int> vec(50001, 0);
        sort(cur.begin(), cur.end());
        for (auto i : cur)
        {
            int e = -1, s = -1;
            bool up = 0;
            for (int j = i.first; j <= i.second; j++)
            {
                vec[j]++;
                if (vec[j] == biggerAns)
                {
                    e = (e == -1 ? j : e);
                    s = j;
                }
                else if (vec[j] > biggerAns)
                {
                    e = ((e == -1 || biggerAns != vec[j]) ? j : e);
                    s = j;
                    biggerAns = vec[j];
                    up = 1;
                    ans.clear();
                }
            }
            if (e != -1 && ans.empty())
                ans.push_back({it->first, e, s + 1});
        }
    }
    int len = 0;
    th an = ans[0];
    cout << an.name << ' ' << an.e << ' ' << an.s;
    return 0;
}
