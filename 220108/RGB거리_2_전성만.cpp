#include <bits/stdc++.h>
using namespace std;
int arr[1001][3];
int dp[1001][3];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int answer = INT_MAX;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> arr[i][j];
        }
    }
    for (int t = 0; t < 3; ++t) {
        dp[1][t] = INT_MAX;
        dp[1][(t+1)%3] = arr[1][(t+1)%3] + arr[0][t];
        dp[1][(t+2)%3] = arr[1][(t+2)%3] + arr[0][t];
        for (int i = 2; i < n; ++i) {
            dp[i][t%3] = arr[i][t%3] + min(dp[i-1][(t+1)%3], dp[i-1][(t+2)%3]);
            dp[i][(t+1)%3] = arr[i][(t+1)%3] + min(dp[i-1][t%3], dp[i-1][(t+2)%3]);
            dp[i][(t+2)%3] = arr[i][(t+2)%3] + min(dp[i-1][t%3], dp[i-1][(t+1)%3]);
        }
        answer = min(answer, min(dp[n-1][(t+1)%3], dp[n-1][(t+2)%3]));
    }
    cout << answer;
    return 0;
}
