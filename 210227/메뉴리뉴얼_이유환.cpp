#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;

void Combination(vector<char> arr, vector<char> comb, int r, int index, int depth)
{
    if (r == 0)
    {
        string tmp = "";
        for (int i = 0; i < comb.size(); i++) {
            tmp += comb[i];
        }           
        m[tmp]++;
    }
    else if (depth == arr.size())  // depth == n
    {
        return;
    }
    else
    {
        comb[index] = arr[depth];
        Combination(arr, comb, r - 1, index + 1, depth + 1);

        Combination(arr, comb, r, index, depth + 1);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) {
        vector<char> tmp;
        for (int j = 0; j < orders[i].length(); j++) {
            tmp.push_back(orders[i][j]);
        }
        sort(tmp.begin(), tmp.end());

        for (int j = 0; j < course.size(); j++) {
            vector<char> comb(course[j]);
            Combination(tmp, comb, course[j], 0, 0);
        }
    }

    for (int i = 0; i < course.size(); i++) {
        int max = 0;
        for (auto it = m.begin(); it != m.end(); it++) {

            if (it->first.length() == course[i]) {
                if (max < it->second) {
                    max = it->second;
                }
            }
        }

        if (max > 1) {
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->first.length() == course[i] && max == it->second) answer.push_back(it->first);
            }
        }

    }

    sort(answer.begin(), answer.end());
    return answer;
}
