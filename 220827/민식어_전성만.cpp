#include <bits/stdc++.h>
using namespace std;
map<string, char> m;
map<string, string> mstr;
int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<string> v;
    // a b c d e f g h i j k l  m n o p q r s t u v w x y z
    // a b k d e g h i l m n ng o p r s t u w y
    for (int i = 0; i < n; i++)
    {
        string str; cin >> str;
        string tmp = "";
        for (int j = 0; j < str.size(); j++)
        {
            switch(str[j])
            {
            case 'k':
            {
                tmp += 'c';
                break;
            }
            case 'g':
            {
                tmp += 'f';
                break;
            }
            case 'h':
            {
                tmp += 'g';
                break;
            }
            case 'i':
            {
                tmp += 'h';
                break;
            }
            case 'l':
            {
                tmp += 'i';
                break;
            }
            case 'm':
            {
                tmp += 'j';
                break;
            }
            case 'n':
            {
                if (j + 1 < str.size() && str[j + 1] == 'g')
                {
                    j++;
                    tmp += 'l';
                }
                else
                {
                    tmp += 'k';
                }
                break;
            }
            case 'o':
            {
                tmp += 'm';
                break;
            }
            case 'p':
            {
                tmp += 'n';
                break;
            }
            case 'r':
            {
                tmp += 'o';
                break;
            }
            case 's':
            {
                tmp += 'p';
                break;
            }
            case 't':
            {
                tmp += 'q';
                break;
            }
            case 'u':
            {
                tmp += 'r';
                break;
            }
            case 'w':
            {
                tmp += 's';
                break;
            }
            case 'y':
            {
                tmp += 't';
                break;
            }
            default:
            {
                tmp += str[j];
                break;
            }
            }
        }
        v.push_back(tmp);
        mstr[tmp] = str;
    }
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << mstr[i] << '\n';
    }

    return 0;
}
