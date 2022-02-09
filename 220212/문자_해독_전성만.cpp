#include <bits/stdc++.h>
using namespace std;
int main() {
    int g, slen, res = 0;
    string w, s;
    cin >> g >> slen >> w >> s;
    vector<int> warr(58, 0), sarr(58, 0);
    for (int i = 0; i < slen; i++) {
        ++sarr[s[i]-'A'];
        if (i < g) warr[w[i]-'A']++;
        else --sarr[s[i-g]-'A'];
        if (i >= g - 1 && sarr == warr) res++;
    }
    cout << res;
    return 0;
}
