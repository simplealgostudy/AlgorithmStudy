#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string start = "";
    int pos = 0;
    for (int i = 0; i < 9; i++) {
            char ch;
            cin >> ch;
            if (ch == '0') pos = i;
            start += ch;
    }
    struct th{
        string s;
        int cnt, pos;
    };
    map<string, int> m;
    queue<th> q;
    m[start] = 1;
    q.push({start, 0, pos});
    int move[4] = {-3, -1, 1, 3};
    while(!q.empty()) {
        th cur = q.front();
        q.pop();
        if (cur.pos == 8 && cur.s == "123456780") {
            cout << cur.cnt;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            if (!(cur.pos % 3) && i == 1) continue;
            if ((cur.pos % 3) == 2 && i == 2) continue;
            th next = {cur.s, cur.cnt + 1, cur.pos + move[i]};
            if (next.pos >= 0 && next.pos < 9) {
                char tmp = next.s[cur.pos];
                next.s[cur.pos] = next.s[next.pos];
                next.s[next.pos] = tmp;
                if (!m[next.s]) {
                    m[next.s] = 1;
                    q.push(next);
                }
            }
        }
    }
    cout << -1;
    return 0;
}