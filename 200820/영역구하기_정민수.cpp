
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> map;
vector<int> answer;

int area;
bool done = false;
int mainIndex[2] = {0};

void drawRectangular(int upperLeftX, int upperLeftY, int bottomRightX, int bottomRightY)
{
    for (int i = upperLeftY; i <= bottomRightY - 1; i++)
    {
        for (int j = upperLeftX; j <= bottomRightX - 1; j++)
        {
            map[i][j] = 1;
        }
    }
}

void minsooSplash(int i, int j)
{
    if (i == map.size() || i < 0 || j < 0 || j == map[0].size())
        return;

    if (map[i][j] == -1 || map[i][j] == 1)
        return;

    map[i][j] = -1;
    area++;

    minsooSplash(i - 1, j); // 상
    minsooSplash(i + 1, j); // 하
    minsooSplash(i, j - 1); // 좌
    minsooSplash(i, j + 1); // 우
}

int* nextStep()
{
    area = 0; // area를 0으로 바꿔줘야 다음 인덱스를 찾았을 때 면적이 0인 채로 시작할 수 있습니다.

    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] == 0)
            {
                mainIndex[0] = i;
                mainIndex[1] = j;
                return mainIndex;
            }
        }
    }
    done = true;
    return 0;
}

int main()
{
    int m; // 행
    int n; // 열
    int k; // 직사각형 갯수

    int upperLeftX;
    int upperLeftY;
    int bottomRightX;
    int bottomRightY;

    cin >> m >> n >> k;
    map.assign(m, vector<int>(n, 0)); // [m][n] 0으로 초기화

    for (int i = 0; i < k; i++)
    {
        cin >> upperLeftX >> upperLeftY >> bottomRightX >> bottomRightY;
        drawRectangular(upperLeftX, upperLeftY, bottomRightX, bottomRightY);
    }

    while (done!=true)
    {
        nextStep();
        minsooSplash(mainIndex[0], mainIndex[1]);
        if(area!=0)answer.push_back(area);
    }

    int amountArea = answer.size();
    sort(answer.begin(), answer.end());

    // 결과출력
    cout << amountArea << endl;
    for (int i = 0; i < amountArea; i++)
    {
        cout<<answer[i]<<" ";
    }
}
