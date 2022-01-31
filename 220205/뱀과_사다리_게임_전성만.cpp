#include <bits/stdc++.h>
using namespace std;
int arr[101];
bool chk[101];
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    for (int i = 1; i <= 100; i++) arr[i] = i;
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cin >> arr[x];
    }
    for (int i = 0; i < m; i++) {
        int u; cin >> u;
        cin >> arr[u];
    }
    queue<int> q;
    q.push(1);
    chk[1] = 1;
    int cnt = 0;
    while (1) {
        int si = q.size();
        while (si--) {
            int cur = q.front();
            q.pop();
            if (cur == 100) {
                cout << cnt;
                return 0;
            }
            for (int i = 1; i <= 6; i++) {
                if (cur + i <= 100) {
                    int next = arr[cur + i];
                    if (!chk[next]) {
                        chk[next] = 1;
                        q.push(next);
                    }
                }
            }
        }
        cnt++;
    }
    return 0;
}