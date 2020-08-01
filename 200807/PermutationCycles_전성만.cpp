#include <bits/stdc++.h>
using namespace std;
int arr[1001];
void dfs(int idx, vector<bool> &chk) {
    if(chk[idx]) {
        return;
    }
    chk[idx] = true;
    dfs(arr[idx], chk);
}

int main() {
    int t;
    for(cin >> t; t--;) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int m;
            cin >> arr[i];
        }
        vector<bool> chk(n+1, false);
        int ans = 0;
        for(int i = 1; i <= n; i++) {
            if (chk[i] == false) {
                ans++;
                dfs(i, chk);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}