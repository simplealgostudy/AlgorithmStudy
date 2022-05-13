#include <bits/stdc++.h>
using namespace std;
int n, arr[502], arr2[502], dp[502][502];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i <= 501; i++) {
        for (int j = 0; j <= 501; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i] >> arr2[i];
        dp[i][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j + i <= n; j++) {
            int e = i + j;
            for (int k = j; k < e; k++) {
                dp[j][e] = min(dp[j][k] + dp[k+1][e] + arr[j] * arr2[k] * arr2[e], dp[j][e]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}