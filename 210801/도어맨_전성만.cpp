#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int n;
    string str; 
    cin >> n >> str;
    stack<char> stk;

    for (int i = str.size() - 1; i >= 0; --i) 
    {
        stk.push(str[i]);
    }

    int m = 0, w = 0;
    while(!stk.empty()) 
    {
        if (abs(m - w) >= n) 
        {
            if (stk.top() == 'W') 
            {
                if (abs(m-(w+1)) >= n) 
                {
                    char tmp = stk.top();
                    stk.pop();
                    if (!stk.empty() && stk.top() == 'M') 
                    {
                        stk.pop();
                        stk.push(tmp);
                        ++m;
                    } 
                    else 
                    {
                        stk.push(tmp);
                        break;
                    }
                } 
                else 
                {
                    w++;
                    stk.pop();
                }
            } 
            else 
            {
                if (abs((m+1)-w) >= n) 
                {
                    char tmp = stk.top();
                    stk.pop();
                    if (!stk.empty() && stk.top() == 'W') 
                    {
                        stk.pop();
                        stk.push(tmp);
                        ++w;
                    } 
                    else 
                    {
                        stk.push(tmp);
                        break;
                    }
                } 
                else 
                {
                    m++;
                    stk.pop();
                }
            }
        } 
        else 
        {
            if (stk.top() == 'W') 
            {
                ++w;
            }
            else
            { 
                ++m;
            }
            stk.pop();
        }
    }

    cout << str.size() - stk.size();
    
    return 0;
}