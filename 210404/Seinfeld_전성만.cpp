#include <iostream>
#include <stack>
using namespace std;
int main() {
    string str;
    int test_case = 1;
    while(cin>>str) {
        if (str[0] == '-') return 0;
        string tmp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i]=='{') tmp += '{';
            else {
                if (tmp.size() && tmp.back() == '{') {
                    tmp.pop_back();
                } else {
                    tmp += '}';
                }
            }
        }
        if (!tmp.size()) {
            cout << test_case++ << ". " << 0 << '\n';
        } else {
            int ans = 0;
            for (int i = 0; i < tmp.size(); i+=2) {
                if (tmp.substr(i,2) == "{{" || tmp.substr(i,2) == "}}") {
                    ans += 1;
                } else if (tmp.substr(i,2) == "}{") {
                    ans += 2;
                }
            }
            cout << test_case++ << ". " << ans << '\n';
        }
    }
    return 0;
}