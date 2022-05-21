#include <bits/stdc++.h>
using namespace std;
char arr[101][101];
int t, h, w, i, j, ans;
void dfs(int y, int x){
    if (y<0||y>=h||x<0||x>=w||'.'==arr[y][x]) return;
    else {
        arr[y][x] = '.';
        dfs(y+1,x);
        dfs(y-1,x);
        dfs(y,x+1);
        dfs(y,x-1);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> h >> w;
        ans = 0;
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                cin >> arr[i][j];
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++)
                if ('#'==arr[i][j]) {
                    ans++;
                    dfs(i, j);
                }
        cout << ans << '\n';
    }
    return 0;
}
