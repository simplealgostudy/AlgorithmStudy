#include <bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            arr[i][j] += (arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1]);
        }
    }
    while(m--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        cout << (arr[x2][y2] - arr[--x1][y2] - arr[x2][--y1] + arr[x1][y1]) << '\n';
    }    
    return 0;
}