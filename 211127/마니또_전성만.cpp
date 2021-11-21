#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int idx = 1;
    while (idx) {
        int n; cin >> n;
        if (!n) return 0;
        map <string, string> m;
        for (int i = 0; i < n; ++i) {
            string str1, str2; cin >> str1 >> str2;
            m[str1] = str2;
        }
        int answer = 0;
        while(!m.empty()) {
            answer++;
            string str = m.begin()->first;
            while (m.find(str) != m.end()) {
                string tmp = m[str];
                m.erase(str);
                str = tmp;
            }
        }
        cout << idx << ' ' << answer << '\n';
        idx++;
    }
    return 0;
}
