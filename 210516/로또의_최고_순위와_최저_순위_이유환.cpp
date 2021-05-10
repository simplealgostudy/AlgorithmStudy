#include <string>
#include <vector>

using namespace std;

int check(int value) {
    int score = 0;
    if (value == 6) {
        score = 1;
    }
    else if (value == 5) {
        score = 2;
    }
    else if (value == 4) {
        score = 3;
    }
    else if (value == 3) {
        score = 4;
    }
    else if (value == 2) {
        score = 5;
    }
    else {
        score = 6;
    }

    return score;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    //6 5 4 3 2
    int max = 0, min = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) max++;
        for (int j = 0; j < win_nums.size(); j++) {
            if (lottos[i] == win_nums[j]) {
                max++;
                min++;
            }
        }
    }

    answer.push_back(check(max));
    answer.push_back(check(min));
    return answer;
}
