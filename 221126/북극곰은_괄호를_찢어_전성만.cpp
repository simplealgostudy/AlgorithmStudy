#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string str; cin >> str;
    int cnt[2] = {0, 0};
    int res = 0;
    for (char chr : str) {
        ++cnt[(chr-'(')];
        res = max(abs(cnt[0]-cnt[1]), res);
    }
    cout << (cnt[0]==cnt[1]?res:-1);
    return 0;
}
