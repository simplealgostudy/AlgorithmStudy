#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int r, c; cin >> r >> c;
    int arr[r+1][c+1];
    memset(arr, 0, sizeof(arr));
    queue<pair<int, int>> q;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (0 == i && 1 == arr[i][j])
            {
                arr[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    int n; cin >> n;
    pair<int, int> move[n+1];
    memset(move, 0, sizeof(move));
    for (int i = 0; i < n; i++)
    {
        cin >> move[i].first >> move[i].second;
    }
    int res = 0;
    while (!q.empty())
    {
        int si = q.size();
        while (si--)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (r - 1 == cur.first)
            {
                cout << res << '\n';
                return 0;
            }
            for (int i = 0; i < n; i++)
            {
                pair<int, int> next = {cur.first + move[i].first, cur.second + move[i].second};
                if (next.first < 0 || next.first >= r || next.second < 0 || next.second >= c || 0 == arr[next.first][next.second]) continue;
                arr[next.first][next.second] = 0;
                q.push(next);
            }
        }
        res++;
    }
    cout << -1;
    return 0;
}
