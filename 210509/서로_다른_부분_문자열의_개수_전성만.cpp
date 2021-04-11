#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    set<string> s;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str.size()-i; j++) {
            string tmp = str.substr(j, 1+i);
            s.insert(tmp);
        }
    }
    cout << s.size();
    return 0;
}
