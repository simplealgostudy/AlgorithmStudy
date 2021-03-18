#include <vector>
using namespace std;
vector<int> numbers_;
int target_, answer;

void fndTarget(int idx, int result) {
    if(numbers_.size() == idx) {
        if(target_ == result) {
            answer++;
        }
        return;
    }
    fndTarget(idx+1, result + numbers_[idx]);
    fndTarget(idx+1, result - numbers_[idx]);
}

int solution(vector<int> numbers, int target) {
    numbers_ = numbers;
    target_ = target;
    answer = 0;
    
    fndTarget(0, 0);
    
    return answer;
}