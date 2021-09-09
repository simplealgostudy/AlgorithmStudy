#include <bits/stdc++.h>
using namespace std;
vector<int> lis (vector<int> v) {
    vector<int> lis(v.size(), 0), di(v.size(), 0), r1(v.size(), 0);
    int len = 1;
    lis[0] = v[0];
    r1[0] = 1;
    for (int i = 1; i < v.size(); ++i) {
        auto b = lis.begin();
        auto e = lis.begin() + len;
        auto it = lower_bound(b, e, v[i]);
        if (it == lis.begin() + len) {
            lis[len++] = v[i];
        } else {
            *it = v[i];
        }
        r1[i] = len;
    }
    return r1;
}
vector<int> swapv(vector<int> v) {
    for (int i = 0; i < v.size() / 2; ++i) {
        int t = v[i];
        v[i] = v[v.size() - 1 - i];
        v[v.size() - 1 - i] = t;
    }
    return v;
}
int main() {
    // freopen("input.in", "r", stdin);
    int n, tmp_max = 0;
    scanf("%d", &n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &v[i]);
    }
    vector<int> r1, r2;
    r1 = lis(v);
    v = swapv(v);
    r2 = swapv(lis(v));
    int res = 0;
    for (int i = 0; i < v.size(); ++i) {
        res = max(res, r1[i] + r2[i] - 1);
    }
    printf("%d", res);
    return 0;
}