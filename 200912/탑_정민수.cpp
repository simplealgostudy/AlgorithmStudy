#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main()
{
    int N;      // 탑의 수
    int height; // 탑의 높이

    stack<pair<int, int> > s;

    scanf("%d", &N);
    int tower[N];
    int answer[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &height);
        tower[i] = height;
    }


    answer[0] = 0;
    s.push(make_pair(0, tower[0]));

    for (int i = 1; i < N; i++)
    {
        while(!s.empty())
        {
            if (s.top().second < tower[i])
            { //엥? 작넹, 수신 실패
                s.pop();
            }
            else // 수신 성공
            {
                answer[i] = s.top().first+1;
                break;
            }
        }
        if (s.empty())
        { //비어있으니까 push해 줄 게 없넹
            // answer.push_back(0);
            answer[i] = 0;
        }
        s.push(make_pair(i, tower[i]));
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", answer[i]);
    }
    return EXIT_SUCCESS;
}
