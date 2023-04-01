#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    string s;
    cin >> n >> m >> s;
    string pattern = "I";
    for (int i = 0; i < n; i++) pattern += "OI";
    vector<int> v(m, 0);
    int p = 1 + (2 * n);
    int res = 0;
    for (int i = 0; i < m; i++)
    {
        if (s[i] == 'O')
        {
            if (i - 1 >= 0 && s[i - 1] == 'I')
                v[i] = v[i-1] + 1;
            else
                v[i] = 0;
        }
        else
        {
            if (i - 1 >= 0 && s[i - 1] == 'O')
            {
                v[i] = v[i-1] + 1;
                if (v[i] >= p)
                    res++;
            }
            else
                v[i] = 1;
        }
    }
    cout << res;
    return 0;
}
