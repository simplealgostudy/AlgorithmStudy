#include <bits/stdc++.h>
using namespace std;
int arr[11];
vector<vector<int>> v(11);
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        int m; cin >> m;
        for (int j = 0; j < m; j++) {
            int l; cin >> l;
            v[i].push_back(l-1);
        }
    }
    int answer = INT_MAX;
    for (int k = 1; k <= n/2; k++) {
        vector<bool> vec(n - k, 0);
        vec.insert(vec.end(), k, 1);
        do {
            vector<bool> chk(n, 0);
            int sum[2] = {0, 0};
            bool check = 0;
            for (int tc = 0; tc <= 1; tc++) {
                int l = 0;
                for (int i = 0; i < n; i++) {
                    if (vec[i] == tc && !chk[i]) {
                        if (!l) {
                            l++;
                            queue<int> q;
                            sum[tc] += arr[i];
                            q.push(i);
                            chk[i] = 1;
                            while (!q.empty()) {
                                int cur = q.front();
                                q.pop();
                                for (auto t : v[cur]) {
                                    if (vec[t] == tc && !chk[t]) {
                                        q.push(t);
                                        sum[tc] += arr[t];
                                        chk[t] = 1;
                                    }
                                }
                            }
                        } else {
                            check = 1;
                            break;
                        }
                    }
                }
                if (check) break;
            }
            if (check) continue;
            answer = min(answer, abs(sum[0] - sum[1]));
        } while(next_permutation(vec.begin(), vec.end()));
    }
    cout << (answer == INT_MAX ? -1 : answer);
    return 0;
}
