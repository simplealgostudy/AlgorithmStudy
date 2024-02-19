#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, f; 
    cin >> n >> f;
    vector<int> v;
    for (int i = 1; i <= n; i++) { v.push_back(i); }
    do
    {
        vector<vector<int>> vec(n, vector<int>(n));
        for (int i = 0; i < n; i++) { vec[0][i] = v[i]; }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                vec[i+1][j] = vec[i][j] + vec[i][j+1];
            }
        }
        if (f == vec[n-1][0])
        {
            for (int i = 0; i < n; i++)
            {
                cout << vec[0][i] << ' ';
            }
            return 0;
        }

    } while (next_permutation(v.begin(), v.end()));
    


    return 0;
}
