#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q; cin >> n >> q;
    unordered_map<int, int> m;
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        int tmp = x, res = 0;
        while (tmp != 1) {
            if (m[tmp]) res = tmp;
            tmp = tmp >> 1;
        }
        cout << res << '\n';
        if (!res) m[x] = 1;
    }
    return 0;    
}