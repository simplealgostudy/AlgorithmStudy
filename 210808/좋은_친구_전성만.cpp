#include <bits/stdc++.h>
using namespace std;
int arr[21];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    queue<int> q;
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        string str; cin >> str;
        q.push(str.size());
        ++arr[str.size()];
        if (!q.empty() && q.size() > k + 1) {
            --arr[q.front()];
            q.pop();
        }
        if (i >= k) {
            res += arr[q.front()] - 1;
        }
    }
    while (!q.empty() && q.size() > 1) {
        --arr[q.front()];
        q.pop();
        res += arr[q.front()] - 1;
    }
    cout << res << '\n';
    return 0;
}