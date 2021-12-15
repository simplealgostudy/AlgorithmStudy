#include <bits/stdc++.h>
using namespace std;
#define MAX 1e6+1
int m[(int)MAX];
int v[(int)MAX];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> m[i];
    for (int i = 0; i < n; ++i) {
        if (i == 0) v[i] = m[i];
        else if (i < k) {
            if (v[i-1] % 2 != m[i]) v[i] = v[i-1] + 1;
            else v[i] = v[i-1];
        } else if (i <= n - k) {
            if ((v[i-1] - v[i-k]) % 2 != m[i]) v[i] = v[i-1] + 1;
            else v[i] = v[i-1];
        } else {
            if ((v[n-k] - v[n-k-(n-i)]) % 2 != m[i]) {
                cout << "Insomnia";
                return 0;
            }
        }
    }
    cout << v[n-k];
    return 0;
}
