#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    long long cnt = 0, tmp = 0;
    unordered_map<long long, long long> um;
    um[tmp]++;
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;
        tmp += t;
        if (um.find(tmp-k) != um.end())
        {
            cnt += um[tmp-k];
        }
        um[tmp]++;
    }

    cout << cnt;
    return 0;
}
