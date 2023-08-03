#include <bits/stdc++.h>
using namespace std;
int pos[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char p[4] = {'U','R','D','L'};
int move(int y, int x, vector<string> &v, int n)
{
    int res = 0;
    while (1)
    {
        if (y < 0 || y >= v.size() || x < 0 || x >= v[0].size() || v[y][x] == 'C') return res;
        if (res > v.size() * 2 * v[0].size()) return -1;
        if (v[y][x] == '/')
        {
            if (n == 0)
                n = 1;
            else if (n == 1)
                n = 0;
            else if (n == 2)
                n = 3;
            else if (n == 3)
                n = 2;
        }
        else if (v[y][x] == '\\')
        {
            if (n == 0)
                n = 3;
            else if (n == 3)
                n = 0;
            else if (n == 1)
                n = 2;
            else if (n == 2)
                n = 1;
        }
        y = y + pos[n][0];
        x = x + pos[n][1];
        res++;
    }
}
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int r, c; cin >> r >> c;
    r--, c--;
    int resp = 0;
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        int num = move(r, c, v, i);
        if (num == -1)
        {
            cout << p[i] << "\nVoyager";
            return 0;
        }
        if (num > result)
        {
            resp = i;
            result = num;
        }
    }
    cout << p[resp] << '\n' << result;
    return 0;
}
