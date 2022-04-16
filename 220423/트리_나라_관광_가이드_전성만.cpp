#include <bits/stdc++.h>
using namespace std;
int chk[100001];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 0; i < 100001; i++) chk[i] = -2;
    int n; cin >> n;
    int k = 0, b = -1;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > k) k = a;
        if (i == 0) chk[a] = -1;
        else if (chk[a] == -2) {
            chk[a] = b;
        }
        b = a;
    }
    cout << k + 1 << '\n';
    for (int i = 0; i <= k; i++) {
        cout << chk[i] << ' ';
    }
    return 0;
}
