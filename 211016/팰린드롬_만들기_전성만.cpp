#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    string tmp = "";
    int idx = 0;
    while (idx < str.size()) {
        string res = str + tmp;
        string rev = res;
        reverse(rev.begin(), rev.end());
        if (! res.compare(rev)) {
            cout << str.size() + idx;
            return 0;
        }
        tmp = str[idx++] + tmp;
    }
    cout << str.size() * 2;
    return 0;
}