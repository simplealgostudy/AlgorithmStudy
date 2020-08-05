// https://www.acmicpc.net/problem/10451

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int integer = 1;
int answer = 0;
bool check[1001];
int array[1001];

void FindCycle(int index, int arr[])
{
    int currentValue = arr[index];
    int size = sizeof(array)/sizeof(*array);

    if (size < integer) // 탈출조건
        return;

    if (check[index] == true) // 방문했음
    {
        integer++;
        FindCycle(integer - 1, array); // skip
    }
    else // 방문한 적 없음
    {
        if (integer == currentValue) // 찾음!
        {
            answer++;
            integer++;
            FindCycle(integer - 1, array);
        }
        else // 아직 못 찾음!
        {
            check[index] = true;
            FindCycle(currentValue - 1, arr);
        }
    }
}
int main()
{
    int testCase;
    int sizeOfArray;
    int value;

    cin >> testCase;
    while (testCase--)
    {
        cin >> sizeOfArray;
        for (int i = 0; i < sizeOfArray; i++)
        {
            cin >> value;
            array[i]=value;
        }
        FindCycle(0, array);
        cout << answer << endl;
        //아래는 초기화
        integer = 1;
        answer = 0;
        fill(check, check+sizeof(check)/sizeof(*check), false);
        fill(array, array+sizeof(array)/sizeof(*array), 0);
        
        EXIT_SUCCESS;
    }
}