// 참고 : https://levenshtein.tistory.com/186

#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5+1;
int arr[MAX];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string s; int k; cin >> s >> k;
    int j = 0;
    for (int i = 1; i < s.size(); i++) {
        while (j && s[i] != s[j]) {
            j = arr[j - 1]; 
        }
        if (s[i] == s[j]) {
            arr[i] = ++j;
        }
    }
    cout << ((s.size() - arr[s.size()-1]) * (k - 1) + s.size());
    return 0;
}