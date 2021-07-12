#include <bits/stdc++.h>
using namespace std;
struct th {
    int r, y, x;
};
bool equalTh(th start, th end) {
    if (start.r == end.r && start.x == end.x && start.y == end.y) {
        return true;
    }
    return false;
}
const int pos[9][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<string> v(n);
    bool chk[2][51][51];
    th start = {-1, -1, -1}, goal = {-1, -1, -1};
    pair<int, int> tmpS = {-1, -1}, tmpG = {-1, -1};
    int startIndex = 0, goalIndex = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < n; j++) {
            if (v[i][j] == 'B') {
                if (tmpS.first == -1 && tmpS.second == -1) {
                    tmpS = {i, j};
                } else if (start.y == -1 && start.x == -1) {
                    start.y = i;
                    start.x = j;
                    if (tmpS.first == start.y) {
                        start.r = 0;
                    } else {
                        start.r = 1;
                    }
                    chk[start.r][i][j] = true;
                }
            }
            else if (v[i][j] == 'E') {
                if (tmpG.first == -1 && tmpG.second == -1) {
                    tmpG = {i, j};
                } else if (goal.y == -1 && goal.x == -1) {
                    goal.y = i;
                    goal.x = j;
                    if (tmpG.first == goal.y) {
                        goal.r = 0;
                    } else {
                        goal.r = 1;
                    }
                }
            }
        }
    }
    queue<pair<th, int>> q;
    q.push({start, 0});
    while(!q.empty()) {
        pair<th, int> cur = q.front();
        q.pop();
        if (equalTh(cur.first, goal)) {
            cout << cur.second;
            return 0;
        }       
        th next;
        for (int i = 0; i < 5; i++) {
            if (!cur.first.r) {
                switch (i) {
                    case 0:
                        next = {cur.first.r, cur.first.y + pos[1][0], cur.first.x + pos[1][1]};
                        if (next.y >= 0 && next.y < n && next.x >= 1 && next.x < n-1 && !chk[0][next.y][next.x] && v[cur.first.y+pos[0][0]][cur.first.x+pos[0][1]] != '1' && v[cur.first.y+pos[1][0]][cur.first.x+pos[1][1]] != '1' && v[cur.first.y+pos[2][0]][cur.first.x+pos[2][1]] != '1') {
                            chk[0][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 1:
                        next = {cur.first.r, cur.first.y + pos[7][0], cur.first.x + pos[7][1]};
                        if (next.y >= 0 && next.y < n && next.x >= 1 && next.x < n-1 && !chk[0][next.y][next.x] && v[cur.first.y+pos[6][0]][cur.first.x+pos[6][1]] != '1' && v[cur.first.y+pos[7][0]][cur.first.x+pos[7][1]] != '1' && v[cur.first.y+pos[8][0]][cur.first.x+pos[8][1]] != '1') {
                            chk[0][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 2:
                        next = {cur.first.r, cur.first.y + pos[3][0], cur.first.x + pos[3][1]};
                        if (next.y >= 0 && next.y < n && next.x >= 1 && next.x < n-1 && !chk[0][next.y][next.x] && v[cur.first.y+pos[3][0]*2][cur.first.x+pos[3][1]*2] != '1') {
                            chk[0][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 3:
                        next = {cur.first.r, cur.first.y + pos[5][0], cur.first.x + pos[5][1]};
                        if (next.y >= 0 && next.y < n && next.x >= 1 && next.x < n-1 && !chk[0][next.y][next.x] && v[cur.first.y+pos[5][0]*2][cur.first.x+pos[5][1]*2] != '1') {
                            chk[0][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 4:
                        next = {1, cur.first.y, cur.first.x};
                        if (next.y >= 1 && next.y < n-1 && next.x >= 1 && next.x < n-1 && !chk[1][next.y][next.x] && v[cur.first.y+pos[0][0]][cur.first.x+pos[0][1]] != '1' && v[cur.first.y+pos[1][0]][cur.first.x+pos[1][1]] != '1' && v[cur.first.y+pos[2][0]][cur.first.x+pos[2][1]] != '1' && v[cur.first.y+pos[6][0]][cur.first.x+pos[6][1]] != '1' && v[cur.first.y+pos[7][0]][cur.first.x+pos[7][1]] != '1' && v[cur.first.y+pos[8][0]][cur.first.x+pos[8][1]] != '1') {
                            chk[1][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                }             
            } else {
                switch (i) {
                    case 0:
                        next = {cur.first.r, cur.first.y + pos[1][0], cur.first.x + pos[1][1]};
                        if (next.y >= 1 && next.y < n-1 && next.x >= 0 && next.x < n && !chk[1][next.y][next.x] && v[cur.first.y+pos[1][0]*2][cur.first.x+pos[1][1]*2] != '1') {
                            chk[1][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 1:
                        next = {cur.first.r, cur.first.y + pos[7][0], cur.first.x + pos[7][1]};
                        if (next.y >= 1 && next.y < n-1 && next.x >= 0 && next.x < n && !chk[1][next.y][next.x] && v[cur.first.y+pos[7][0]*2][cur.first.x+pos[7][1]*2] != '1') {
                            chk[1][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 2:
                        next = {cur.first.r, cur.first.y + pos[3][0], cur.first.x + pos[3][1]};
                        if (next.y >= 1 && next.y < n-1 && next.x >= 0 && next.x < n && !chk[1][next.y][next.x] && v[cur.first.y+pos[0][0]][cur.first.x+pos[0][1]] != '1' && v[cur.first.y+pos[3][0]][cur.first.x+pos[3][1]] != '1' && v[cur.first.y+pos[6][0]][cur.first.x+pos[6][1]] != '1') {
                            chk[1][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 3:
                        next = {cur.first.r, cur.first.y + pos[5][0], cur.first.x + pos[5][1]};
                        if (next.y >= 1 && next.y < n-1 && next.x >= 0 && next.x < n && !chk[1][next.y][next.x] && v[cur.first.y+pos[2][0]][cur.first.x+pos[2][1]] != '1' && v[cur.first.y+pos[5][0]][cur.first.x+pos[5][1]] != '1' && v[cur.first.y+pos[8][0]][cur.first.x+pos[8][1]] != '1') {
                            chk[1][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                    case 4:
                        next = {0, cur.first.y, cur.first.x};
                        if (next.y >= 1 && next.y < n-1 && next.x >= 1 && next.x < n-1 && !chk[0][next.y][next.x] && v[cur.first.y+pos[0][0]][cur.first.x+pos[0][1]] != '1' && v[cur.first.y+pos[2][0]][cur.first.x+pos[2][1]] != '1' && v[cur.first.y+pos[3][0]][cur.first.x+pos[3][1]] != '1' && v[cur.first.y+pos[5][0]][cur.first.x+pos[5][1]] != '1' && v[cur.first.y+pos[6][0]][cur.first.x+pos[6][1]] != '1' && v[cur.first.y+pos[8][0]][cur.first.x+pos[8][1]] != '1') {
                            chk[0][next.y][next.x] = 1;
                            q.push({next, cur.second + 1});
                        }
                        break;
                }
            }
        }
    }
    cout << 0;
    return 0;
}