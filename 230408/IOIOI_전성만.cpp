#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m;
    string s;
    cin >> n >> m >> s;
    int p = 1 + (2 * n), b = (s[0]=='I'?1:0), res = 0;
    for (int i = 1; i < m; i++)
    {
        if (s[i] != s[i-1]) b++;
        else
            b = (s[i] == 'I' ? 1 : 0);
        if (s[i] == 'I' && b >= p) res++;
    }
    cout << res;
    return 0;
}
