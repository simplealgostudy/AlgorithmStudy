#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> answer;

int solution(int num, int sqr)
{
    answer.push_back(num);
        int sum = 0;
        while (num>0) {
            sum += pow(num % 10, sqr);
            if (num < 10)
                break;
            num /= 10;
        }
 
        for (int i = 0; i < answer.size()-1; i++) {
            if (answer[i] == answer.back()) {
                return i;
            }
        }
        solution(sum, sqr);
}

int main(void) {
    cout<<solution(57, 2);
}
