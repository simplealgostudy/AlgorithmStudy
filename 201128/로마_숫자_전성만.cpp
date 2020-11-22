#include <bits/stdc++.h>
using namespace std;

int num[91];

int romaToInt(string str) 
{
    int ans = num[str[0]];
    for (int i = 1; i < str.size(); i++) 
    {
        if (num[str[i-1]] < num[str[i]]) 
        {
            ans += num[str[i]] - (2 * num[str[i-1]]);
        }
        else
        { 
            ans += num[str[i]];
        }
    }
    return ans;
}

int main() 
{
    num['I'] = 1, num['V'] = 5, num['X'] = 10, num['L'] = 50, num['C'] = 100, num['D'] = 500, num['M'] = 1000;

    string str1, str2; 
    cin >> str1 >> str2;

    int ans = romaToInt(str1) + romaToInt(str2);
    cout << ans << '\n';

    string chr[3001];
    chr[1] = "I", chr[4] = "IV", chr[5] = "V", chr[9] = "IX", chr[10] = "X", chr[40] = "XL", chr[50] = "L", chr[90] = "XC", chr[100] = "C", chr[400] = "CD", chr[500] = 'D', chr[900] = "CM", chr[1000] = "M";
    for (int i = 1; i <= 1000; i *= 10) 
    {
        chr[i*2] = chr[i] + chr[i], chr[i*3] = chr[i*2] + chr[i];
        if (i <= 100) 
        {
            chr[i*6] = chr[i*5] + chr[i], chr[i*7] = chr[i*6] + chr[i], chr[i*8] = chr[i*7] + chr[i];        
        }
    }

    string str = "";
    for (int tmp = 1000; tmp > 0; tmp /= 10) 
    {
        int bloc = ans / tmp;
        if (bloc) 
        {
            str += chr[bloc * tmp];
        }
        ans %= tmp;
    }

    cout << str << '\n';
    
    return 0;
}