#include <bits/stdc++.h>
using namespace std;
int n, m, k, a, b, c;
map<int, int> mii;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        mii[a] = b;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a;
        switch (a) {
        case 1: {
            cin >> b >> c;
            mii[b] = c;
            break;
        }
        case 2: {
            cin >> b >> c;
            auto low = mii.lower_bound(b);
            if (low->first != b) low--;
            auto up = mii.upper_bound(b);
            int lowval = abs(low->first - b);
            int upval = abs(up->first - b);
            if (lowval > upval && upval <= k) {
                mii[up->first] = c;
            } else if (lowval < upval && lowval <= k) {
                mii[low->first] = c;
            } else if (low->first == up->first && lowval <=k) {
                mii[low->first] = c;
            }
            break;
        }
        case 3: {
            cin >> b;
            auto low = mii.lower_bound(b);
            if (low->first != b) low--;
            auto up = mii.upper_bound(b);
            int lowval = abs(low->first - b);
            int upval = abs(up->first - b);
            if (lowval > upval && upval <= k) {
                cout << up->second << '\n';
            } else if (lowval < upval && lowval <= k) {
                cout << low->second << '\n';
            } else if (lowval == upval && lowval <=k) {
                if (low->first == up->first) {
                    cout << low->second << '\n';
                } else {
                    cout << "?\n";
                }
            } else {
                cout << -1 << '\n';
            }
            break;
        }
        }
    }
    return 0;
}
