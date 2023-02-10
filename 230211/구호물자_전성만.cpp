#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<vector<int>> v(n, vector<int>(n, 1e9));
    for (int i = 0; i < n - 1; i++)
    {
        int t; cin >> t;
        for (int j = 0; j < t; j++)
        {
            int k; cin >> k;
            v[i][k-1] = 1;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][k] + v[k][j] < v[i][j])
                {
                    v[i][j] = v[i][k] + v[k][j];
                }
            }
        }
    }
    bool chk = 0;
    for (int i = 0; i < n; i++)
        if (v[0][i] < 1e9 && v[i][i] < 1e9)
            chk = 1;
    
    cout << (chk ? "CYCLE" : "NO CYCLE");
    return 0;
}