#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin >> n;
    string str;
    cin >> str;
    // s - m * u / p + c return
    int result = 0;
    bool output = false;
    bool ins = false;
    queue<int> q;
    queue<char> qc;
    int num = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            num *= 10;
            num += (str[i] - '0');
            ins = true;
        }
        else
        {
            if (ins)
            {
                q.push(num);
                num = 0;
                ins = false;
            }
            if ('C' == str[i])
            {
                int tmpsum = 0; 
                if (!q.empty())
                {
                    tmpsum = q.front();
                    q.pop();
                }
                while (!q.empty() && !qc.empty())
                {
                    char tqc = qc.front();
                    qc.pop();
                    int tq = q.front();
                    q.pop();
                    switch (tqc)
                    {
                    case 'S':
                    {
                        tmpsum -= tq;
                        break;
                    }
                    case 'M':
                    {
                        tmpsum *= tq;
                        break;
                    }
                    case 'U':
                    {
                        tmpsum /= tq;
                        break;
                    }
                    case 'P':
                    {
                        tmpsum += tq;
                        break;
                    }
                    }
                }
                cout << tmpsum << ' ';
                q.push(tmpsum);
                output = true;
            }
            else
            {
                qc.push(str[i]);
            }
        }
    }
    if (false == output)
    {
        cout << "NO OUTPUT";
    }
    return 0;
}
