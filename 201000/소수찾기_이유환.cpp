#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

vector<int> arr;
vector<int> choice;
vector<int> v;
vector<int> answer_v;

void check()
{

    int count = 0;
    int tmp = 0;
    for (int i = 0; i < v.size(); i++)
    {   
        tmp += v[i] * pow(10, i);       
    }
    answer_v.push_back(tmp);

}

void DFS(int Cnt, int K, int numbersSize)
{
    if (Cnt == K)
    {
        check();    
    }

    for (int i = 0; i < numbersSize; i++)
    {
        if (choice[i] == true) continue;
        choice[i] = true;
        v.push_back(arr[i]);
        DFS(Cnt + 1, K, numbersSize);
        v.pop_back();
        choice[i] = false;
    }
}

int solution(string numbers) {
    string tmp = "";

    for (int i = 0; i < numbers.length(); i++) {
        tmp += numbers[i];
        arr.push_back(stoi(tmp));
        tmp = "";
        choice.push_back(-1);
    }

    for (int i = 1; i <= numbers.length(); i++) {
        DFS(0, i, numbers.length());
    }

    sort(answer_v.begin(), answer_v.end());
    answer_v.erase(unique(answer_v.begin(), answer_v.end()), answer_v.end());

    int answer = 0;
    int count = 0;
    for (int i = 0; i < answer_v.size(); i++) {
        if (answer_v[i] > 1) {
            for (int j = 2; j <= (answer_v[i] / 2); j++) {
                if (answer_v[i] % j == 0) count++;
            }
        }
        else
            count = 1;

        if (count == 0) answer++;
        count = 0;
    }

    return answer;
}
