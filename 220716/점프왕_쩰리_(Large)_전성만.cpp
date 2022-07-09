#include <bits/stdc++.h>
using namespace std;
int arr[65][65], pos[2][2] = {{0,1},{1,0}};
bool chk[65][65];
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> arr[i][j];
        }
    }
    if (arr[0][0])
    {
        chk[0][0] = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        while (! q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (-1 == arr[cur.first][cur.second])
            {
                cout << "HaruHaru";
                return 0;
            }
            int num = arr[cur.first][cur.second];
            for (int i = 0; i < 2; i++)
            {
                pair<int, int> next = {cur.first + pos[i][0] * num, cur.second + pos[i][1] * num};
                if (next.first >= n || next.second >= n || chk[next.first][next.second]) continue;
                chk[next.first][next.second] = 1;
                q.push({next});
            }

        }
    }
    cout << "Hing";
    return 0;
}
