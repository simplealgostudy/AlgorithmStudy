#include <bits/stdc++.h>
using namespace std;

char arr[6][6];
bool chk[6][6];

int r, c, k, pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int answer = 0;

bool check(int row, int col)
{
    return (row == 1 && col == c);
}

void dfs(int row, int col, int cnt)
{
    if (cnt >= k)
    {
        if (check(row, col))
        {
            answer++;
        }
        return;
    }
    if (check(row, col))
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int n_row = row + pos[i][0];
        int n_col = col + pos[i][1];
        if (n_row < 1 || n_row > r || n_col < 1 || n_col > c || 'T' == arr[n_row][n_col] || chk[n_row][n_col]) continue;
        chk[n_row][n_col] = 1;
        dfs(n_row, n_col, cnt + 1);
        chk[n_row][n_col] = 0;
    }
}


int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c >> k;
    for (int i = 1; i <= r; i++)
    {
        string str; cin >> str;
        for (int j = 1; j <= c; j++)
        {
            arr[i][j] = str[j-1];
        }
    }
    chk[r][1] = 1;
    dfs(r, 1, 1);
    cout << answer;
    return 0;
}
