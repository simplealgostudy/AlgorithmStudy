#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; 
    string str; 
    cin >> n >> str;
    int res = 0;
    int arr[2] = {0, 0};
    int rev[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        ++arr[str[i]-'('];
        ++rev[str[n-i]-'('];
        if (arr[0] == arr[1])
            res = max(arr[0] * 2, res);
        if (arr[0] < arr[1]) 
            memset(arr, 0, sizeof(arr));
        if (rev[0] == rev[1])
            res = max(rev[0] * 2, res);
        if (rev[0] > rev[1])
            memset(rev, 0, sizeof(rev));
    }
    cout << res;
    return 0;
}