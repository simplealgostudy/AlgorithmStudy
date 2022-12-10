#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> folder;
unordered_map<string, unordered_map<string, int>> file;
unordered_map<string, pair<int, int>> res;

unordered_map<string, int> dfs(string cur, string name)
{
    pair<int, int> pii = {0, 0};
    unordered_map<string, int> ums = file[cur];
    for (auto it : folder[cur])
    {
        string nextname = name;
        nextname += "/";
        nextname += it;
        unordered_map<string, int> plus = dfs(it, nextname);
        for (auto it = plus.begin(); it != plus.end(); ++it)
        {
            ums[it->first] += it->second;
        }
    }
    res[name].first = ums.size();
    for (auto it = ums.begin(); it != ums.end(); it++)
    {
        res[name].second += it->second;
    }
    return ums;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; 
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
    {
        string s1, s2, s3; 
        cin >> s1 >> s2 >> s3;
        if ("1" == s3)
        {
            folder[s1].push_back(s2);
        }
        else
        {
            file[s1][s2]++;
        }
    }
    dfs("main", "main");
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        pair<int, int> cur = res[str];
        cout << cur.first << ' ' << cur.second << '\n';
    }
    return 0;
}
