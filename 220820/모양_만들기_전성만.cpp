#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];
bool chk[1001][1001];
int sum[1001][1001];
int n, m, pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    set<pair<int, int>> pset;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] && !chk[i][j])
            {
                pset.clear();
                int aSum = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                chk[i][j] = 1;
                while (! q.empty())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                        if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || chk[next.first][next.second]) continue;
                        if (0 == arr[next.first][next.second])
                        {
                            pset.insert(next);
                        }
                        else 
                        {
                            chk[next.first][next.second] = 1;
                            aSum++;
                            q.push(next);
                        }
                    }
                }
                for (auto v : pset)
                {
                    sum[v.first][v.second] += aSum;
                    ans = max(ans, sum[v.first][v.second]);
                }
            }
        }
    }
    cout << ans + 1;
    return 0;
}
