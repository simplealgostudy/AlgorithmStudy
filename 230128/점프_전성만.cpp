#include <bits/stdc++.h>
using namespace std;
long long arr[101][101];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, p; cin >> n;
    arr[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p;
            if (0 == p)
                continue;
            if (i + p < n)
                arr[i+p][j] += arr[i][j];
            if (j + p < n)
                arr[i][j+p] += arr[i][j];
        }
    }
    cout << arr[n-1][n-1];
    return 0;
}
