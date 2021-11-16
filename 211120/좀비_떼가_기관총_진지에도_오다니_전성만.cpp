#include <bits/stdc++.h>
using namespace std;
#define MAX (int)3e6+1
long long arr[MAX];
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int l, m, k, c; cin >> l >> m >> k >> c;
    queue<int> q;
    for (int i = 0; i < l; ++i) cin >> arr[i];
    long long at = 0, cm = 0;
    queue<int> cmidx;
    for (int i = 0; i < l; ++i) {
        if (at < k * m) at += k;
        if (!cmidx.empty() && cmidx.front() + m == i) {
            cmidx.pop();
            cm -= k;
        }
        long long next = at - cm;
        if (arr[i] > next) {
            if (c) {
                c--;
                cmidx.push(i);
                cm += k;
            } else {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
