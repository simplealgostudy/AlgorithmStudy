#include <bits/stdc++.h>
using namespace std;
vector<queue<string>> v;
void splitstr(string str) {
    queue<string> q;
    stringstream ss(str);
    string s;
    while (getline(ss, s, ' ')) q.push(s);
    v.push_back(q);
}
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    cin.ignore();
    map<string, int> m;
    string str = "";
    for (int i = 1; i <= n; ++i) {
        getline(cin, str);
        splitstr(str);        
        if (!v[i-1].empty()) {
            m[v[i-1].front()] = i;
            v[i-1].pop();
        }
    }
    getline(cin, str);
    splitstr(str);
    while (!v[n].empty()) {
        string tmp = v[n].front();
        v[n].pop();
        if (m[tmp]) {
            int t = m[tmp] - 1;
            if (!v[t].empty()) {
                m[v[t].front()] = t + 1;
                v[t].pop();
            }
            m.erase(tmp);
        } else {
            cout << "Impossible";
            return 0;
        }
    }
    if (m.size()) {
        cout << "Impossible";
        return 0;
    }
    cout << "Possible";
    return 0;
}
