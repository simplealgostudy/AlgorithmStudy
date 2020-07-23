#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > v(9);
int number_;

int add(int a, int b){return a+b;}
int sub(int a, int b){return a-b;}
int mul(int a, int b){return a*b;}
int DIV(int a, int b){return int(a/b);}

bool calculat(int n) {
    for(int i = 1; i < n; i++)
    {
        int rev = n - i;
        for(int j = 0; j < v[i].size(); j++)
        {
            for (int z = 0; z < v[rev].size(); z++)
            {
                int res = add(v[i][j], v[rev][z]);
                if(number_ == res)
                {
                    return true;
                }
                v[n].emplace_back(res);
                res = sub(v[i][j], v[rev][z]);
                if(number_ == res)
                {
                    return true;
                }
                v[n].emplace_back(res);
                res = mul(v[i][j], v[rev][z]);
                if(number_ == res)
                {
                    return true;
                }
                v[n].emplace_back(res);
                if(v[rev][z] != 0)
                {
                    res = DIV(v[i][j], v[rev][z]);
                    if(number_ == res)
                    {
                        return true;
                    }
                    v[n].emplace_back(res);
                }
            }
        }
    }
    return false;
}

int solution(int N, int number) {
    v[1].emplace_back(N);
    number_ = number;
    for(int i = 2; i < 9; i++)
    {
        v[i].emplace_back(v[i-1][0] * 10 + N);
    }
    
    for(int i = 2; i < 9; i++)
    {
        if(number == v[i][0])
        {
            return i;
        }
        if(calculat(i))
        {
            return i;
        }
    }
    
    return -1;
}