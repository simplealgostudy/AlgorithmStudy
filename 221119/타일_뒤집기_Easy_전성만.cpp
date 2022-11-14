#include <bits/stdc++.h>
using namespace std;
bool check(int y, int x, int& n)
{
    if (y < 0 || y >= n || x < 0 || x >= n)
    {
        return false;
    }
    return true;
}
char chchar(int y, int x, vector<string>& vs)
{
    if ('#' == vs[y][x])
        return '.';
    else
        return '#';
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    string str; cin >> str;
    vector<string> vs(n, string(n, '.'));
    vs[0] = str;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ('#' == vs[i][j])
            {
                int n_y = i + 1;
                int n_x = j - 1;
                if (check(n_y, n_x, n))
                {
                    vs[n_y][n_x] =  chchar(n_y,n_x,vs);
                }
                n_y = i + 1;
                n_x = j + 1;
                if (check(n_y, n_x, n))
                {
                    vs[n_y][n_x] =  chchar(n_y,n_x,vs);
                }
                n_y = i + 2;
                n_x = j;
                if (check(n_y, n_x, n))
                {
                    vs[n_y][n_x] =  chchar(n_y,n_x,vs);
                }
            }
        }
    }
    for (auto s : vs)
    {
        cout << s << '\n';
    }
    return 0;
}
