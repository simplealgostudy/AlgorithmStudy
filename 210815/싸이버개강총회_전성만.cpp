#include <bits/stdc++.h>
using namespace std;
int getTime(string str) {return (str[0] - '0') * 600 + (str[1] - '0') * 60 + (str[3] - '0') * 10 + str[4] - '0';}
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int getT[3];
    for (int i = 0; i < 3; i++) {
        string tmp; cin >> tmp;
        getT[i] = getTime(tmp);
    }
    map<string, int> m;
    int result = 0;
    while(!cin.eof()) {
        string time, nickname;
        cin >> time >> nickname;
        int t = getTime(time);
        if (t <= getT[0]) {
            m[nickname] = 1;
        } else if (t > getT[0] && t < getT[1]) {
            continue;
        } else if (t >= getT[1] && t <= getT[2]) {
            if (m[nickname] == 1) {
                m[nickname] = 2;
                ++result;
            }
        }
    }
    cout << result;
    return 0;   
}