#include <bits/stdc++.h>
using namespace std;
struct cor {
    int r_y, r_x, b_y, b_x;
};
string str[11];
int m, n;
pair<int, int> red, blue, hol;
const int pos[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
bool checkGoal(pair<int, int> tmp) {
    if (tmp.first == hol.first && tmp.second == hol.second) {
        return true;
    }
    return false;
}
pair<int, int> movepoint(pair<int, int> next, int p) {
    while (1) {
        pair<int, int> tmp = {next.first + pos[p][0], next.second + pos[p][1]};
        if (tmp.first >= 0 && tmp.first < m && tmp.second >= 0 && tmp.second < n && str[tmp.first][tmp.second] != '#') {
            if (checkGoal(tmp)) return tmp;
            next = tmp;
        } else {
            break;
        }
    }
    return next;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);    
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        str[i] = s;
        for (int j = 0; j < n; j++) {
            switch(s[j]) {
                case 'O':
                    hol = {i, j};
                    break;
                case 'R':
                    red = {i, j};
                    break;
                case 'B':
                    blue = {i, j};
                    break;
            }
        }
    }
    queue<cor> q;
    q.push({red.first, red.second, blue.first, blue.second});
    for (int testcase = 0; testcase < 10; ++testcase) {
        int qsize = q.size();
        while(qsize--) {
            cor cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> n_r = {cur.r_y, cur.r_x};
                pair<int, int> n_b = {cur.b_y, cur.b_x};
                int ra = n_r.second, rb = n_b.second, rc = n_r.first, rd = n_b.first;
                if (i == 3) {
                    swap(rc, rd);
                }
                if (i == 1 || i == 2) {
                    swap(ra, rc);
                    swap(rb, rd);
                    if (i == 2) {
                        swap(rc, rd);
                    }
                }
                if (ra == rb) {
                    if (rc < rd) {
                        n_r = movepoint(n_r, i);
                        n_b = movepoint(n_b, i);
                        if (checkGoal(n_b)) {
                            continue;
                        }
                        if (checkGoal(n_r)) {
                            cout << 1;
                            return 0;
                        }
                        if(n_r.first == n_b.first && n_r.second == n_b.second) n_b = {n_r.first + pos[3-i][0], n_r.second + pos[3-i][1]};
                        q.push({n_r.first, n_r.second, n_b.first, n_b.second});
                    } else {
                        n_b = movepoint(n_b, i);
                        if (checkGoal(n_b)) {
                            continue;
                        }
                        n_r = movepoint(n_r, i);
                        if (checkGoal(n_r)) {
                            cout << 1;
                            return 0;
                        }
                        if(n_r.first == n_b.first && n_r.second == n_b.second) n_r = {n_b.first + pos[3-i][0], n_b.second + pos[3-i][1]};
                        q.push({n_r.first, n_r.second, n_b.first, n_b.second});
                    }
                } else {
                    n_r = movepoint(n_r, i);
                    if (checkGoal(n_r)) {
                        cout << 1;
                        return 0;
                    }                            
                    n_b = movepoint(n_b, i);
                    if (checkGoal(n_b)) {
                        continue;
                    }
                    q.push({n_r.first, n_r.second, n_b.first, n_b.second});
                }
            }
        }
    }
    cout << 0;
    return 0;
}