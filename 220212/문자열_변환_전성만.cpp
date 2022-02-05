#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        string a, b; cin >> a >> b;
        int ai = 0, bi = 0, ans = 0, n = a.size();
        while (ai < n && bi < n) {
            while (ai < n && a[ai]!='a') ai++;
            while (bi < n && b[bi]!='a') bi++;
            if (ai < n && bi < n) ans += abs(ai - bi);
            ai++, bi++;
        }
        cout << ans << '\n';
    }
    return 0;
}
