#include <algorithm>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    int i  = 0;
    for(i = 0; i < completion.size(); i++) {
        if(participant[i] != completion[i])
            return participant[i];
    }    
    return participant[i];
}