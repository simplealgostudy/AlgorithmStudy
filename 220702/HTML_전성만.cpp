#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    map<string, string> m;
    m["<br>"] = "\n";
    m["<hr>"] = string(80, '-') + "\n";
    int length = 0;
    string str;
    string ans = "";
    bool chk = 0;
    while (cin >> str)
    {
        if (m.find(str) != m.end())
        {
            if (! str.compare("<br>"))
            {
                ans += m[str];
            }
            else
            if (! str.compare("<hr>"))
            {
                if (0 == chk || 0 != length)
                {
                    ans += "\n";
                }
                ans += m[str];
            }
            length = 0;
        }
        else
        {
            if (0 != length)
            {
                str = " " + str;
            }
            if (length + str.size() > 80)
            {
                length = str.size();
                ans += ("\n" + str.substr(1));
            }
            else
            {
                length += str.size();
                ans += str;
            }
        }
        chk = 1;
    }
    cout << ans;
    return 0;
}