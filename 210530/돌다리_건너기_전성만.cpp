#include <bits/stdc++.h>
using namespace std;
long long arr[21][2][101];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string pattern, str[2]; 
    cin >> pattern >> str[0] >> str[1];
    int patternLen = pattern.size(), strLen = str[0].size();
    for (int i = 0; i < 2; i++) if (str[i][0] == pattern[0]) arr[0][i][0] = 1;
    for (int i = 1; i < strLen; i++) {
        for (int j = 0; j < 2; j++) {
            if (str[j][i] == pattern[0]) {
                arr[0][j][i] = arr[0][j][i-1] + 1;
            } else {
                arr[0][j][i] = arr[0][j][i-1];
            }
        }
    }
    for (int i = 1; i < patternLen; i++) {
        for (int j = i; j < strLen; j++) {
            for (int k = 0; k < 2; k++) {
                if (str[k][j] == pattern[i]) {
                    if (k == 0) {
                        if (arr[i-1][1][j-1] > 0) {
                            arr[i][0][j] = arr[i-1][1][j-1] + arr[i][0][j-1];
                        } else {
                            arr[i][k][j] = arr[i][k][j-1];
                        }
                    } else {
                        if (arr[i-1][0][j-1] > 0) {
                            arr[i][1][j] = arr[i-1][0][j-1] + arr[i][1][j-1];
                        } else {
                            arr[i][k][j] = arr[i][k][j-1];
                        }
                    }
                } else {
                    arr[i][k][j] = arr[i][k][j-1];
                }            
            }
        }
    }
    cout << arr[patternLen-1][0][strLen-1] + arr[patternLen-1][1][strLen-1];
    return 0;
}