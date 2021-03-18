#include <cmath>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) 
{
    vector<int> answer(2);
    int brye = brown + yellow;
    int fac = int(sqrt(brye));
    for (int i = 3; i <= fac; i++)
    {
        if (brye % i == 0)
        {
            int j = brye / i;
            int ini = i - 2;
            int inj = j - 2;
            if (yellow == ini * inj && brown == brye - yellow)
            {
                answer[0] = j;
                answer[1] = i;
                return answer;
            }
        }
    }
    
    return answer;
}