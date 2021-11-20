#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    map<string, vector<string>> member;
    map<string, string> group;
    while(n--) {
        string groupname; cin >> groupname;
        int t; cin >> t;
        vector<string> v;
        while (t--) {
            string name; cin >> name;
            group[name] = groupname;
            v.push_back(name);
        }
        sort(v.begin(), v.end());
        member[groupname] = v;
    }
    while(m--) {
        string tmp; cin >> tmp;
        int idx; cin >> idx;
        if (idx) {
            cout << group[tmp] << '\n';
        } else {
            for (auto v : member[tmp]) {
                cout << v << '\n';
            }
        }
    }
    return 0;
}
