#include <bits/stdc++.h>
using namespace std;
int r, c;
vector<string> vstr(251);
vector<vector<bool>> chk(251, vector<bool>(251, 0));
void dfs(int y, int x, int &tsheep, int &twolf)
{
    if (y < 0 || y >= r || x < 0 || x >= c || chk[y][x] || vstr[y][x] == '#') 
    {
        return;
    }
    chk[y][x] = 1;
    char curchr = vstr[y][x];
    if (curchr == 'v')
    {
        ++twolf;
    }
    else if (curchr == 'k')
    {
        ++tsheep;
    }
    dfs(y-1,x,tsheep,twolf);
    dfs(y+1,x,tsheep,twolf);
    dfs(y,x-1,tsheep,twolf);
    dfs(y,x+1,tsheep,twolf);
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c;
    //  v 늑대, k 양
    // if v < k v = 0, else k = 0
    for (int i = 0; i < r; i++)
    {
        cin >> vstr[i];
    }
    int sheep = 0, wolf = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char curchr = vstr[i][j];
            if ((curchr == 'v' || curchr == 'k') && !chk[i][j])
            {
                int tsheep = 0, twolf = 0;
                dfs(i, j, tsheep, twolf);
                if (tsheep > twolf)
                {
                    twolf = 0;
                }
                else
                {
                    tsheep = 0;
                }
                sheep += tsheep;
                wolf += twolf;
            }
        }
    }
    cout << sheep << ' ' << wolf;
    return 0;
}
