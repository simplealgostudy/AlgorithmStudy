// 참고 : wiki.mathnt.net/index.php?title=카탈란_수_(Catalan_numbers)
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
long long dp[5001][2501];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    dp[2][0] = dp[2][1] = 1;
    for (int i = 4; i <= 5000; i+=2) 
    {
        for (int j = 0; j <= i/2; j++) 
        {
            if(j==0) 
            {
                dp[i][j] = 1;
            }
            else if (j == i/2) 
            {
                dp[i][j] = dp[i][j-1];
            } 
            else 
            {
                dp[i][j] = (dp[i-2][j] + dp[i][j-1]) % MOD;
            }
        }
    }

    int t;
    for (cin >> t; t--;) 
    {
        int l;
        cin >> l;
        cout << dp[l][l/2] << '\n';
    }
}