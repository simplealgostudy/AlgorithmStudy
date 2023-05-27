#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vector<int> r, per;
    set<int> s;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0, c; j < k; j++)
        {
            cin >> c;
            s.insert(1<<(c-1));
            sum += (1<<(c-1));
        }
        r.push_back(sum);
    }
    for (auto it = s.begin(); it != s.end(); it++)
        per.push_back(*it);
    vector<bool> chk(per.size(), 0);
    for (int i = 0; i < n; i++)
        chk[i] = 1;
    int ans = 0;
    do
    {
        int nSum = 0;
        for (int i = 0; i < chk.size(); i++)
        {
            if (!chk[i]) continue;
            nSum += per[i];
        }
        int curRes = 0;
        for (int i = 0; i < m; i++)
        {
            int cur = nSum & r[i];
            if (cur == r[i]) curRes++;
        }
        ans = max(ans, curRes);
    } while (prev_permutation(chk.begin(), chk.end()));
    cout << ans;
    return 0;
}
