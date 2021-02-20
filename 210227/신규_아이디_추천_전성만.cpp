#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) 
{
    string answer = "";
    locale loc;

    for (string::size_type i=0; i<new_id.length(); ++i) 
    {
        answer += tolower(new_id[i],loc);
    }

    regex("[^0-9a-z-_.]");
    answer = regex_replace (answer,regex("[^0-9a-z-_.]"),"");
    answer = regex_replace (answer,regex("[.]+"),".");
    answer = regex_replace (answer,regex("^[.]|[.]$"),"");
    answer = (answer == "" ? "aaa" : (answer.size() > 15) ? answer.substr(0, 15) : answer);
    answer = regex_replace (answer, regex("[.]$"),"");
    if (answer.size() == 1) 
    {
        answer += (answer + answer);
    }
    if (answer.size() == 2) 
    {
        answer += (answer[1]);
    }
    
    return answer;
}