#include <string>
#include <vector>

using namespace std;

int answer = 0;
void dfs(int idx, int sum, int target, vector<int>& numbers)
{
    if (idx == numbers.size())
    {
        if (sum == target)
            answer++;
        return;
    }

    dfs(idx+1, sum + numbers[idx], target, numbers);
    dfs(idx+1, sum - numbers[idx], target, numbers);
}
int solution(vector<int> numbers, int target) {

    dfs(0, 0 ,target, numbers);
    return answer;
}