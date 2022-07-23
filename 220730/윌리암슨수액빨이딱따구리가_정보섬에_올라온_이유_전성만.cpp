#include <bits/stdc++.h>
using namespace std;
string str[3001];
bool chk[3001][3001];
int n, m, pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n >> m;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++){
        cin >> str[i];
        for (int j = 0; j < m; j++){
            if ('2' == str[i][j]){
                str[i][j] = '0';
                q.push({i, j});
                chk[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while (!q.empty()){
        int si = q.size();
        while(si--){
            pair<int, int> cur = q.front();
            q.pop();
            if ('0' != str[cur.first][cur.second]){
                cout << "TAK\n" << cnt;
                return 0;
            }
            for (int i = 0; i < 4; i++){
                pair<int, int> next = {cur.first + pos[i][0], cur.second + pos[i][1]};
                if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m || '1' == str[next.first][next.second] || true == chk[next.first][next.second]) continue;
                chk[next.first][next.second] = 1;
                q.push(next);
            }
        }
        cnt++;
    }
    cout << "NIE";
    return 0;
}
