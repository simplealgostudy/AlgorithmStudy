#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    map<int, string> m;
    int x; 
    cin >> x;
    string str; 
    cin >> str;
    string tmp = str;
    int cnt = 0;

    m[cnt] = str;
    int strSize = str.size();

    while(1) 
    {
        ++cnt;
        string t = "";
        if (strSize%2) 
        {
            for (int i = 0; i < (strSize/2); i++) 
            {
                t += tmp[i];
                t += tmp[strSize - i - 1];
            }
            t += tmp[strSize/2];
        } 
        else 
        {
            for (int i = 0; i < strSize/2; i++) 
            {
                t += tmp[i];
                t += tmp[strSize - i - 1];
            }
        }

        tmp = t;
        m[cnt] = tmp;

        if (tmp == str) 
        {
            break;
        }
    }
    
    cout << m[cnt - x%cnt];

    return 0;
}