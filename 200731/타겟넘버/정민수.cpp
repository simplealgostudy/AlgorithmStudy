#include <string>
#include <vector>
#include <iostream>

using namespace std;

void recursion(vector<int> numbers, int i, int adding, int target, int& answer)
{
    if(numbers.size()==i){
        if(adding==target){
            answer++;
        }
        return;
    }
    recursion(numbers, i+1, adding+numbers[i], target, answer);
    recursion(numbers, i+1, adding-numbers[i], target, answer);
}

int solution(vector<int> numbers, int target)
{
    int answer = 0;
    recursion(numbers, 0, 0, target, answer);
    return answer;
}

int main()
{
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(numbers, target) << endl;
}