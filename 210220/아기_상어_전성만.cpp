#include <bits/stdc++.h>
using namespace std;
struct shark_ {
    int y, x, weight, cnt;
};
bool sortby(const pair<int,int> &a, const pair<int,int> &b) {
    if (a.first != b.first) return a.first < b.first;
    else return (a.second < b.second); 
} 
const int POS[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int d[n][n];
    int M = 0;
    shark_ shark;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
            if (d[i][j] > 0 && d[i][j] < 7) M++;
            else if (d[i][j] == 9) {
                shark = {i, j, 2, 0};
                d[i][j] = 0;
            }
        }
    }
    int res = 0, eat = 0;
    bool chk[n][n];
    while(M--) {
        bool check = false;
        memset(chk, false, sizeof(chk));
        chk[shark.y][shark.x] = true;
        queue<shark_> q;
        q.push(shark);
        int count = 1e9;
        vector<pair<int, int>> next_s;
        while(!q.empty()) {
            shark_ cur = q.front();
            q.pop();
            if (count < cur.cnt) {
                continue;
            }
            if (d[cur.y][cur.x] && cur.weight > d[cur.y][cur.x]) {
                check = true;
                if (count > cur.cnt) {
                    next_s.clear();
                    next_s.push_back({cur.y, cur.x});
                    count = cur.cnt;
                } else if (count == cur.cnt) {
                    next_s.push_back({cur.y, cur.x});
                }
                continue;
            }
            chk[cur.y][cur.x] = true;
            for (int i = 0; i < 4; i++) {
                pair<int, int> next = {cur.y+POS[i][0], cur.x+POS[i][1]};
                if (next.first<0 || next.first>=n || next.second<0 || next.second>=n || chk[next.first][next.second] || cur.weight < d[next.first][next.second]) continue;
                q.push({next.first, next.second, cur.weight, cur.cnt+1});
            }
        }
        if (!check) break;
        else {
            eat++;
            res += count;
            sort(next_s.begin(), next_s.end(), sortby);
            shark = {next_s[0].first, next_s[0].second, shark.weight, 0};
            d[next_s[0].first][next_s[0].second] = 0;
        }
        if (eat == shark.weight) {
            shark.weight++;
            eat = 0;
        }
    }
    cout << res;
    return 0;
}
