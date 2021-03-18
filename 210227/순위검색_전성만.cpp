#include <bits/stdc++.h>
using namespace std;
vector<int> solution(vector<string> info, vector<string> query) {
    map<string, vector<int>> m;
    for (int i = 0; i < info.size(); i++) {
        int cnt = 0;
        string tmp = "";
        vector<vector<string>> tmp_s(16,vector<string>(4,"-"));
        for (int j = 0; j < info[i].size(); j++) {
            if (info[i][j] == ' ') {
                if(cnt == 0) {
                    for (int z = 0; z < 8; z++) tmp_s[z][0] = tmp;                    
                } else if (cnt == 1) {
                    for (int z = 0; z < 4; z++) tmp_s[z][1] = tmp;
                    for (int z = 8; z < 12; z++) tmp_s[z][1] = tmp;
                } else if (cnt == 2) {
                    for (int z = 0; z < 16; z+=4) {
                        tmp_s[z][2] = tmp;
                        tmp_s[z+1][2] = tmp;
                    }
                } else if (cnt == 3) {
                    for (int z = 0; z < 16; z+=2) tmp_s[z][3] = tmp;
                }
                cnt++;
                tmp = "";
            } else {
                tmp += info[i][j];                
            }
        }
        int tmp_n = stoi(tmp);
        for (int z = 0; z < 16; z++) {
            m[tmp_s[z][0]+tmp_s[z][1]+tmp_s[z][2]+tmp_s[z][3]].push_back(tmp_n);
        }
    }
    for (map<string, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }
    vector<int> answer;
    for (int i = 0; i < query.size(); i++) {
        int cnt = 0;
        string tmp = "";
        string tmp_str = "";
        for (int j = 0; j < query[i].size(); j++) {
            if (query[i][j] == ' ' && cnt < 3) {
                cnt++;
                j += 4;
            } else if (query[i][j] == ' ') { 
                cnt++;
            } else if (cnt == 4) {
                tmp_str += query[i][j];
            } else {
                tmp += query[i][j];
            }
        }
        int tmp_n = stoi(tmp_str);
        if (m.find(tmp) != m.end()) {
            vector<int>::iterator low = lower_bound(m.find(tmp)->second.begin(), m.find(tmp)->second.end(), tmp_n);
            answer.push_back(m.find(tmp)->second.size()-(low-m.find(tmp)->second.begin()));
        } else {
            answer.push_back(0);
        }
    }    
    return answer;
}