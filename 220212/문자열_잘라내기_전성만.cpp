#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int r, c, count = 0; cin >> r >> c;
    vector<string> str(r); 
    for (int i = 0; i < r; i++) cin >> str[i];
    vector<string> tmp(c);
    for (int i = 0; i < c; i++) {
        string s = "";
        for (int j = r - 1; j >= 0; j--) {
            s += str[j][i];
        }
        tmp[i] = s;
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < c-1; i++) {
        for (int j = 0; j < r; j++) {
            if (tmp[i][j] != tmp[i+1][j]) {
                count = max(count, j);
                break;
            }
        }
    }
    cout << r - 1 - count;
    return 0;
}
