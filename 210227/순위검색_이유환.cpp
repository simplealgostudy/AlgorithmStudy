#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {

    map<string, vector<int>> m;

    for (int i = 0; i < info.size(); i++) {
        string tmp1 = "";
        string tmp2 = "";
        string tmp3 = "";
        string tmp4 = "";
        string tmp_ = "";
        string score = "";
        int count = 0;

        for (int j = 0; j < info[i].length(); j++) {
            if (info[i][j] == ' ') count++;
            if (info[i][j] != ' ' && count < 1) {                           
                tmp1 += info[i][j];         
            }
            else if (info[i][j] != ' ' && count < 2) {
                tmp2 += info[i][j];
            }
            else if (info[i][j] != ' ' && count < 3) {
                tmp3 += info[i][j];
            }
            else if (info[i][j] != ' ' && count < 4) {
                tmp4 += info[i][j];
            }
            if (info[i][j] != ' ' && count >= 4) {
                score += info[i][j];
            } 
        }
        m[tmp1 + tmp2 + "--"].push_back(stoi(score));
        m[tmp1 + tmp2 + '-' + tmp4].push_back(stoi(score));
        m[tmp1 + tmp2 + tmp3 + '-'].push_back(stoi(score));
        m[tmp1 + tmp2 + tmp3 + tmp4].push_back(stoi(score));
        m[tmp1 + "---"].push_back(stoi(score));
        m[tmp1 + "--" + tmp4].push_back(stoi(score));
        m[tmp1 + '-' + tmp3 + '-'].push_back(stoi(score));
        m[tmp1 + '-' + tmp3 + tmp4].push_back(stoi(score));
        m['-' + tmp2 + "--"].push_back(stoi(score));
        m['-' + tmp2 + '-' + tmp4].push_back(stoi(score));
        m['-' + tmp2 + tmp3 + '-'].push_back(stoi(score));
        m['-' + tmp2 + tmp3 + tmp4].push_back(stoi(score));
        m["----"].push_back(stoi(score));
        m["---" + tmp4].push_back(stoi(score));
        m["--" + tmp3 + '-'].push_back(stoi(score));
        m["--" + tmp3 + tmp4].push_back(stoi(score));

    }

    for (auto it = m.begin(); it != m.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    vector<int> answer;
    for (int i = 0; i < query.size(); i++) {
        string tmp = "";
        string check = "";
        string score = "";
        int scoreT = 0;
        int count = 0;
        for (int j = 0; j < query[i].size(); j++) {
            if (query[i][j] != ' ') {
                tmp += query[i][j];
            }
            if (query[i][j] == ' ') {
                if (tmp != "and") {
                    count++;
                    check += tmp;
                }
                tmp = "";
            }
            if (query[i][j] != ' ' && count >= 4) {
                score += query[i][j];
            }
        }

        if (m.find(check) != m.end()) {

            vector<int>::iterator low = lower_bound(m.find(check)->second.begin(), m.find(check)->second.end(), stoi(score));           
            answer.push_back(m.find(check)->second.size() - (low - m.find(check)->second.begin()));
        }
        else answer.push_back(0);
    }

    return answer;
}
