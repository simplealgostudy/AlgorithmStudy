#include <bits/stdc++.h>
using namespace std;
int n, m, i, j;
vector<vector<int>> v(21, vector<int>(21, 0)), chk(21, vector<int>(21, 0));
map<pair<int, int>, int> mp;
map<pair<pair<int, int>, pair<int, int>>, int> mpt;
int dfs(int y, int x, vector<pair<int, int>> &vp, vector<vector<int>> &chk_tmp) {
    if (y >= 0 && y < n && x >= 0 && x < m && !chk_tmp[y][x] && v[y][x] != 1) {
        chk_tmp[y][x] = 1;
        if (v[y][x] == 2) {
            chk[y][x] = 1;
            return dfs(y-1, x, vp, chk_tmp) + dfs(y+1, x, vp, chk_tmp) + dfs(y, x-1, vp, chk_tmp) + dfs(y, x+1, vp, chk_tmp) + 1;
        }
        if (v[y][x] == 0) {
            vp.push_back({y, x});
            return 0;
        }
    }
    return 0;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    for (i = 0; i < n; i++) for (j = 0; j < m; j++) cin >> v[i][j];
    int res = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == 2 && !chk[i][j]) {
                vector<pair<int, int>> vp;
                vector<vector<int>>  chk_tmp(n, vector<int>(m , 0));
                int cnt = 0;
                int res_tmp = dfs(i, j, vp, chk_tmp);
                if (vp.size() == 1) mp[vp[0]] += res_tmp;
                if (vp.size() == 2) {
                    if (vp[0].first < vp[1].first) {
                        mpt[{vp[0], vp[1]}] += res_tmp;
                    } else if (vp[0].first > vp[1].first) {
                        mpt[{vp[1], vp[0]}] += res_tmp;
                    } else {
                        if (vp[0].second < vp[1].second) {
                            mpt[{vp[0], vp[1]}] += res_tmp;
                        } else if (vp[0].second >= vp[1].second) {
                            mpt[{vp[1], vp[0]}] += res_tmp;
                        } 
                    }
                }
            }
        }
    }
    for (auto it = mpt.begin(); it != mpt.end(); ++it) {
        if (mp[{it->first.first.first, it->first.first.second}]) it->second += mp[{it->first.first.first, it->first.first.second}];
        if (mp[{it->first.second.first, it->first.second.second}]) it->second += mp[{it->first.second.first, it->first.second.second}];
        res = max(res, it->second);
    }
    int max1 = 0, max2 = 0;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (max1 <= it->second) {
            max2 = max1;
            max1 = it->second;
        } else if (max2 < it->second) {
            max2 = it->second;
        }
    }
    res = max(res, max1 + max2);
    cout << res;
    return 0;
}