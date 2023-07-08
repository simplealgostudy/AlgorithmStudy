#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    while (true)
    {
        int n; cin >> n;
        if (0 == n) return 0;
        string str; cin.ignore(); getline(cin, str);
        map<char, int> m;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < str.size(); r++)
        {
            m[str[r]]++;
            while (m.size() > n)
            {
                m[str[l]]--;
                if (0 == m[str[l]])
                    m.erase(str[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        cout << ans << '\n';
    }
    return 0;
}
