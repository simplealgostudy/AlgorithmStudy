#include<bits/stdc++.h>

using namespace std;

string ans;

// Java -> Cpp
void toCpp(string str) 
{
    for (int i = 0; i < str.size(); i++) 
    {
        // 중간에 '_' 가 있을 경우 Error
        if(str[i]=='_') 
        {
            ans = "Error!";

            return;
        }

        // 대문자가 있을 경우
        if(str[i]>='A'&&str[i]<='Z') 
        {
            ans += '_';
            ans += (str[i] + ('a' - 'A'));

            continue;
        }

        // 소문자에 경우
        ans += str[i];
    }

    return;
}

// Cpp -> Java
void toJava(string str) 
{
    int i = 0;

    while(i < str.size()) 
    {
        // 마지막이 '_' 일 경우 Error
        if(i==str.size()-1 && str[i]=='_') 
        {
            ans = "Error!";

            return;
        }

        // 대문자가 있을 경우 Error
        if(str[i]>='A'&&str[i]<='Z') 
        {
            ans = "Error!";

            return;
        }

        // '_'일 경우
        if(str[i]=='_') 
        {
            i++; // 다음 문자로

            // '_'가 또 있을 경우 Error
            if(str[i]=='_') 
            {
                ans = "Error!";

                return;
            }

            // 대문자가 나올 경우 Error
            if(str[i]>='A'&&str[i]<='Z') 
            {
                ans = "Error!";

                return;
            }

            // 소문자 -> 대문자
            ans += (str[i] - ('a' - 'A'));

            i++; // 다음 문자로

            continue;
        }

        // 위에 경우 해당되지 않을 경우
        ans += str[i++];
    }

    return;
}

int main() 
{
    string str; 
    cin >> str;

    for(int i = 0; i < str.size(); i++) 
    {
        // '_' 로 시작 시 Error
        if(i == str.size() - 1 && str[i] == '_') 
        {
            ans = "Error!";

            break;
        }

        // 대문자로 시작 시 Error
        if(i==0 && (str[i] == '_' || (str[i] >= 'A' && str[i] <= 'Z'))) 
        {
            ans = "Error!";

            break;
        }

        // '_'가 있을 경우 toJava
        if(str[i] == '_')
        {
            ans = str.substr(0, i);
            toJava(str.substr(i, str.size()));

            break;
        }

        // 대문자가 있을 경우 toCpp
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            ans = str.substr(0, i);
            toCpp(str.substr(i, str.size()));

            break;
        }

        // 중간에 아무 것도 없을 경우 그대로 출력
        if(i == str.size() - 1) 
        {
            ans = str.substr(0, str.size());
        }
    }

    // 결과
    cout << ans;
}