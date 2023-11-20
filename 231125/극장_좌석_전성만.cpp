#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int m; cin >> m;
    int ans = 1;
    int b = 0, t = 0;
    vector<int> v(41,0);
    v[0]=1;
    v[1]=1;
    for (int i = 2; i <= 40; i++) v[i] = v[i-1] + v[i-2];
    for (int i = 0; i < m; i++)
    {
        int k; cin >> k;
        t = k - b - 1;
        b = k;
        ans *= v[t];
    }
    t = n - b;
    ans *= v[t];
    cout << ans;
    return 0;
}
