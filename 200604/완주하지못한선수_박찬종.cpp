#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int find = 0;
    int size = 0;
    size = participant.size();

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < size; i++) {
        if (participant[i] == (completion[i]))
            continue;
        else {
            find = i;
            break;
        }
    }
    string answer = participant[find];
    return answer;
}

int main()
{
    vector<string> participant;
    vector<string> completion;
    participant.push_back("mislav");
    participant.push_back("stanko");
    participant.push_back("mislav");
    participant.push_back("ana");
    completion.push_back("stanko");
    completion.push_back("ana");
    completion.push_back("mislav");

    cout << solution(participant, completion) << endl;
}
