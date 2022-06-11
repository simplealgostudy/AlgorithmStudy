#include <bits/stdc++.h>
using namespace std;
string str[2];
bool chk[2][(int)1e6+1];

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k, t = 0; cin >> n >> k;    
    cin >> str[0] >> str[1];
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    chk[0][0] = 1;
    while (!q.empty())
    {
        int si = q.size();
        while (si--)
        {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.second >= n)
            {
                cout << 1;
                return 0;
            }
            if (cur.second - 1 > t && '1' == str[cur.first][cur.second - 1] && !chk[cur.first][cur.second - 1])
            {
                chk[cur.first][cur.second - 1] = 1;
                q.emplace(cur.first, cur.second - 1);
            }
            if (cur.second + 1 >= n || (cur.second + 1 < n && '1' == str[cur.first][cur.second + 1] && !chk[cur.first][cur.second + 1]))
            {
                if (cur.second + 1 < n) chk[cur.first][cur.second + 1] = 1;
                q.emplace(cur.first, cur.second + 1);
            }
            if (cur.second + k >= n || (cur.second + k < n && '1' == str[(cur.first + 1) % 2][cur.second + k] && !chk[(cur.first + 1) % 2][cur.second + k]))
            {
                if (cur.second + k < n) chk[(cur.first + 1)%2][cur.second + k] = 1;
                q.emplace((cur.first + 1) % 2, cur.second + k);
            }
        }
        t++;
    }
    cout << 0;
    return 0;
}
