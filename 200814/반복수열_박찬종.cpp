#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> answer;
int ans=0;

void solution(int num, int sqr)
{
    answer.push_back(num);
    int sum = 0;
    while (num > 0) {
        sum += pow(num % 10, sqr);
        num /= 10;
    }

    for (int i = 0; i < answer.size() - 1; i++) {
        if (answer[i] == answer.back()) {
            ans = i;
            return;
        }
    }
    solution(sum, sqr);
}

int main(void) {
    int n, p;
    cin >> n >> p;
    solution(n, p);
    cout << ans;
}
