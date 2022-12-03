#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; 
    cin >> n;
    int larr[26], rarr[26];
    memset(larr, 0, sizeof(larr));
    memset(rarr, 0, sizeof(rarr));
    vector<pair<int, int>> vp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        larr[str[0]-'A']++;
        rarr[str[1]-'A']++;
        vp.push_back({str[0]-'A', str[1]-'A'});
    }
    for (int i = 1; i < 26; i++)
    {
        larr[i] += larr[i-1];
        rarr[i] += rarr[i-1];
    }
    map<char, int> m;
    for (auto p : vp)
    {
        int a1 = rarr[p.first], a2 = larr[p.second];
        if (p.first <= p.second)
        {
            a2 -= 1;
        }
        if (p.first >= p.second)
        {
            a1 -= 1;
        }
        if (a1 > 0)
            m[p.first + 'A'] = 1;
        if (a2 > 0)
            m[p.second + 'A'] = 1;
    }
    cout << m.size() << '\n';
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << ' ';
    }
    return 0;
}
