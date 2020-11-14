#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    while(1) 
    {
        int w, h; cin >> w >> h;
        if (!w && !h) return 0;

        bool chk[h][w];
        memset(chk, false, sizeof(chk));

        int d[h][w];
        for (int i = 0; i < h; i++) for (int j = 0; j < w; j++) cin >> d[i][j];
            
        pair<int, int> pos[8] ={{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
        
        int ans = 0;
        for (int i = 0; i < h; i++) 
        {
            for (int j = 0; j < w; j++) 
            {
                if (!chk[i][j] && d[i][j]) 
                {
                    ++ans;
                    chk[i][j] = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()) 
                    {
                        pair<int, int> cur = q.front();
                        q.pop();
                        for (int i = 0; i < 8; i++) 
                        {
                            pair<int, int> next = {cur.first + pos[i].first, cur.second + pos[i].second};
                            if (next.first < 0 || next.first >= h || next.second < 0 || next.second >= w || chk[next.first][next.second] || !d[next.first][next.second]) continue;
                            chk[next.first][next.second] = 1;
                            q.push({next.first, next.second});
                        }
                    }
                }
            }
        }

        cout << ans << '\n';
    }
    
    return 0;
}