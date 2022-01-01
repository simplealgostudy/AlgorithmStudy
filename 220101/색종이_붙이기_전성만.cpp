#include <bits/stdc++.h>
using namespace std;
struct pos {
    int arr[10][10];
    int cnt;
    int res;
    int ans[5];
};
int cal(int y, int x, int tmp[10][10]) {
    int arr[10][10];
    copy(&tmp[0][0],&tmp[0][0]+10*10,&arr[0][0]);
    int idx = 0;
    int i = y;
    int j = x;
    for (int i = y; i < y + 5; ++i) {
        if (i >= 10) break;
        j = x;
        if (j + idx >= 10) break;
        for (j = x; j < x + 5; ++j) {
            if (j >= 10) break;
            if (arr[i][j] && i > 0 && j > 0) {
                arr[i][j] = min(arr[i-1][j], min(arr[i][j-1], arr[i-1][j-1])) + 1;
            }
        }
        if (y +idx < 10 && x + idx < 10 && arr[y+idx][x+idx] != idx + 1) break;
        idx++;
    }
    return idx;
}
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int arr[10][10];
    int cnt = 0;
    for (int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j) {
            cin >> arr[i][j];
            if (arr[i][j]) ++cnt;
        }
    }
    queue<pos> q;
    pos p;
    copy(&arr[0][0], &arr[0][0]+10*10, &p.arr[0][0]);
    p.cnt = cnt;
    p.res = 0;
    memset(p.ans, 0, sizeof(p.ans));
    q.push(p);
    int answer = 26;
    while (!q.empty()) {
        pos cur = q.front();
        q.pop();
        if (cur.res >= answer) continue;
        else if (!cur.cnt) {
            if (cur.res < answer) {
                answer = cur.res;
            }
            continue;
        }
        bool chk = false;
        for(int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (cur.arr[i][j]) {
                    chk = 1;
                    int mo = cal(i, j, cur.arr);
                    for (int k = 0; k < mo; ++k) {
                        if (cur.ans[k] + 1 > 5) continue;
                        pos next = cur;
                        next.ans[k]++;
                        next.res++;
                        next.cnt -= ((k+1)*(k+1));
                        for (int l = i; l <= i + k;++l) {
                            for (int m = j; m <= j + k; ++m) {
                                next.arr[l][m] = 0;
                            }
                        }
                        q.push(next);
                    }
                    break;
                }
            }
            if (chk) break;
        }
    }
    cout << (answer==26?-1:answer);
    return 0;
}
