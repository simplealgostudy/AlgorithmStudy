#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    string str; 
    cin >> n >> str;
    int m = n / 5;
    string ans = "";
    int idx = 0;
    while (idx < m) {
        if (str[idx] == '#') {
            if (idx+1 < m) {
                int i = idx + 1, j = idx + 2;
                if (str[idx + 1] == '.') {
                    if (str[idx + 1 + (2 * m)] == '#') {
                        ans += '4';
                    } else {
                        ans += '1';
                        idx += 1;
                        continue;
                    }
                } else if (str[idx + 1 + (2 * m)] == '.'){
                    if (str[idx + 1 + (4 * m)] == '#') {
                        ans += '0';
                    } else {
                        ans += '7';
                    }
                } else if (str[idx + m] == '.') {
                    if (str[idx + (3 * m)] == '#') {
                        ans += '2';
                    } else {
                        ans += '3';
                    }
                } else if (str[idx + (3 * m)] == '.') {
                    if (str[idx + 2 + m] == '.') {
                        ans += '5';
                    } else {
                        ans += '9';
                    }
                } else {
                    if (str[idx + 2 + m] == '.') {
                        ans += '6';
                    } else {
                        ans += '8';
                    }
                }
                idx += 3;
            } else {
                ans += '1';
                ++idx;
            }
        } else {
            ++idx;
        }
    }
    cout << ans;
    return 0;
}