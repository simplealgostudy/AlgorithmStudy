#include <bits/stdc++.h>
using namespace std;
bool chk[8][8][8];
char ch[8][8][8];
struct th
{
    int z, y, x;
};
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int move[9][2] = {{0,0},{0,-1},{0,1},{-1,0},{-1,-1},{-1,1},{1,0},{1,-1},{1,1}};
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cin >> ch[0][i][j];
        }
    }
    for (int i = 1; i < 8; i++) 
    {
        for (int j = 7; j >= 1; j--)
        {
            for (int k = 0; k < 8; k++)
            {
                ch[i][j][k] = ch[i-1][j-1][k];
            }
        }
        for (int k = 0; k < 8; k++)
            ch[i][0][k] = '.';
    }

    queue<th> q;
    q.push({0, 7, 0});
    bool res = 0;
    while (!q.empty())
    {
        th cur = q.front();
        q.pop();
        if (cur.z == 7 && cur.y == 0 && cur.x == 7)
        {
            res = 1;
            break;
        }
        if (cur.z + 1 < 8) 
            cur.z += 1;
        
        for (int i = 0; i < 9; i++)
        {
            int y_ = cur.y + move[i][0];
            int x_ = cur.x + move[i][1];
            if (y_ < 0 || y_ >= 8 || x_ < 0 || x_ >= 8 || 1 == chk[cur.z][y_][x_] || '#' == ch[cur.z-1][y_][x_] || '#' == ch[cur.z][y_][x_]) continue;
            chk[cur.z][y_][x_] = 1;
            q.push({cur.z, y_, x_});
        }
    }
    cout << res;
    return 0;
}
