#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> solution(vector<string> orders, vector<int> course) {
    map<string, int> m[11];
    for (int i = 0; i < orders.size(); i++) {
        vector<string> str;
        str.push_back("");
        sort(orders[i].begin(), orders[i].end());
        for (int j = 0; j < orders[i].size(); j++) {
            int str_size = str.size();
            for (int z = 0; z < str_size; z++) {
                str.push_back(str[z]+orders[i][j]);
            }
        }
        for (int i = 0; i < str.size(); i++) {
            if(m[str[i].size()].find(str[i]) == m[str[i].size()].end()) {
                m[str[i].size()][str[i]] = 1;
            } else {
                m[str[i].size()].find(str[i])->second++;
            }
        }
    }
    vector<string> answer;
    for (int i = 0; i < course.size(); i++) {
        vector<string> tmp;
        int max_value = 2;
        for (map<string, int>::iterator it = m[course[i]].begin(); it != m[course[i]].end(); it++) {
            if (it->second > max_value) {
                tmp.clear();
                tmp.push_back(it->first);
                max_value = it->second;
            } else if(it->second == max_value) {
                tmp.push_back(it->first);                
            }
        }
        for (auto i : tmp) {
            answer.push_back(i);
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}