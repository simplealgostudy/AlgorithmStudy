#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    cin.ignore();
    while(n--) {
        string str;
        getline(cin, str);
        int res = 0, ans = 0;
        for (auto c : str) {
            if (c == '[') ans = ++res > ans ? res : ans;
            else --res;
        }
        cout << (1<<ans) << '\n';
    }
    return 0;
}
