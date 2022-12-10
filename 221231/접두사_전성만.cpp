#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int res = n;
    for (int i = 1; i < n; i++)
    {
        if (v[i-1].size() > v[i].size()) continue;
        if (v[i].substr(0, v[i-1].size()) == v[i-1])
            res--;
    }
    cout << res;
    return 0;
}
