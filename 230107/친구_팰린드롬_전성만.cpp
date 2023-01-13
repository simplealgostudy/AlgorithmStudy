#include <bits/stdc++.h>
using namespace std;
bool chk[21];
int arr[51][2];
int res = 0, n, m;
void dfs(int idx, int cnt)
{
    if (m == idx)
    {
        if (res < cnt * 2)
            res = cnt * 2;
        return;
    }
    if (chk[arr[idx][0]] || chk[arr[idx][1]])
    {
        dfs(idx + 1, cnt);
        return;
    }
    chk[arr[idx][0]] = 1;
    chk[arr[idx][1]] = 1;
    dfs(idx + 1, cnt + 1);
    chk[arr[idx][0]] = 0;
    chk[arr[idx][1]] = 0;
    dfs(idx + 1, cnt);
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> arr[i][0] >> arr[i][1];
    dfs(0, 0);
    if (res < n)
        res += 1;
    cout << res;
    return 0;
}
