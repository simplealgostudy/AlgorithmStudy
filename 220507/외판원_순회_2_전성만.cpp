#include <bits/stdc++.h>
using namespace std;
int v[11][11], chk[10][1<<10], n;
constexpr int MAX = 9e6+1;
int tsp(int cur, int visit) {
    int check = chk[cur][visit];
    if (check != -1) return check;
    if (visit == (1 << n) - 1) {
        if (v[cur][0] != 0) return v[cur][0];
        else return MAX;
    }
    check = MAX;
    for (int i = 0; i < n; i++) {
        if (v[cur][i] && !(visit & (1 << i))) {
            int next = visit | (1 << i);
            check = min(check, tsp(i, next) + v[cur][i]);
        }
    }
return check;
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    memset(chk, -1, sizeof(chk));
    cout << tsp(0, 1);
    return 0;
}
