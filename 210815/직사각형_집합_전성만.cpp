#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    map<pair<long long, long long>, int> m;
    for (long long y = 1; y < 500; ++y) {
        for (long long x = y+1; x < 500; ++x) {
            long long w = x*x-y*y, h = 2 * x * y, d = x*x+y*y;
            if (w*w+h*h==d*d) {
                long long tmp = __gcd(w, __gcd(h, d));
                m[{min(w/tmp, h/tmp), max(w/tmp, h/tmp)}] = 1;
            }
        }
    }
    vector<int> v;
    for (auto it = m.begin(); it != m.end(); it++) {
        v.push_back(2 * (it->first.first + it->first.second));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
        v[i] += v[i-1];
    }
    while (t--) {
        int l; cin >> l;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == l) {
                cout << i + 1<< '\n';
                break;
            }
            else if (v[i] > l) {
                cout << i << '\n';
                break;
            }
        }
    }
    return 0;    
}