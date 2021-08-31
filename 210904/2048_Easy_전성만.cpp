#include <bits/stdc++.h>
using namespace std;

int res = 0;
int n;

int findMaxValue(vector<vector<int>> v) 
{
    int tmp = 0;
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (tmp < v[i][j]) tmp = v[i][j];
        }
    }

	return tmp;
}

vector<vector<int>> moveVector(vector<vector<int>> v, int p) 
{
    switch(p) 
    {
        case 0: 
        {
            for (int i = 0; i < n; ++i) 
            {
                stack<int> stk;
                for (int j = n-1; j >= 0; --j) 
                {
                    if (v[i][j] > 0) stk.push(v[i][j]);
                }
                int j = 0;
                int tmp = 0;
                while (!stk.empty()) 
                {
                    if (!tmp) 
                    {
                        tmp = stk.top();
                    } 
                    else 
                    {
                        if (tmp == stk.top()) 
                        {
                            v[i][j++] = (tmp * 2);
                            tmp = 0;
                        } 
                        else 
                        {
                            v[i][j++] = tmp;
                            tmp = stk.top();
                        }
                    }
                    stk.pop();
                }
				if (tmp) 
                {
					v[i][j++] = tmp;
				}
				for (int k = j; k < n; ++k) v[i][k] = 0;
            }
            break;
        }

        case 1: 
        {
            for (int i = 0; i < n; ++i) 
            {
                stack<int> stk;
                for (int j = 0; j < n; ++j) 
                {
                    if (v[i][j] > 0) stk.push(v[i][j]);
                }
                int j = n - 1;
                int tmp = 0;
                while (!stk.empty()) 
                {
                    if (!tmp) 
                    {
                        tmp = stk.top();
                    } 
                    else 
                    {
                        if (tmp == stk.top()) 
                        {
                            v[i][j--] = (tmp * 2);
                            tmp = 0;
                        } 
                        else 
                        {
                            v[i][j--] = tmp;
                            tmp = stk.top();
                        }
                    }
                    stk.pop();
                }  
				if (tmp) 
                {
					v[i][j--] = tmp;
				}
				for (int k = j; k >= 0; --k) v[i][k] = 0;              
            }
            break;
        }

        case 2: 
        {
            for (int i = 0; i < n; ++i) 
            {
                stack<int> stk;
                for (int j = n-1; j >= 0; --j) 
                {
                    if (v[j][i] > 0) stk.push(v[j][i]);
                }
                int j = 0;
                int tmp = 0;
                while (!stk.empty()) 
                {
                    if (!tmp) 
                    {
                        tmp = stk.top();
                    } 
                    else 
                    {
                        if (tmp == stk.top()) 
                        {
                            v[j++][i] = (tmp * 2);
                            tmp = 0;
                        } 
                        else 
                        {
                            v[j++][i] = tmp;
                            tmp = stk.top();
                        }
                    }
                    stk.pop();
                }         
				if (tmp) 
                {
					v[j++][i] = tmp;
				} 
				for (int k = j; k < n; ++k) v[k][i] = 0;      
            }
            break;
        }

        case 3: 
        {
            for (int i = 0; i < n; ++i) 
            {
                stack<int> stk;
                for (int j = 0; j < n; ++j) 
                {
                    if (v[j][i] > 0) stk.push(v[j][i]);
                }
                int j = n - 1;
                int tmp = 0;
                while (!stk.empty()) 
                {
                    if (!tmp) 
                    {
                        tmp = stk.top();
                    } 
                    else 
                    {
                        if (tmp == stk.top()) 
                        {
                            v[j--][i] = (tmp * 2);
                            tmp = 0;
                        } 
                        else 
                        {
                            v[j--][i] = tmp;
                            tmp = stk.top();
                        }
                    }
                    stk.pop();
                } 
				if (tmp) 
                {
					v[j--][i] = tmp;
				}
				for (int k = j; k >= 0; --k) v[k][i] = 0;              
            }
            break;
        }
    }
    return v;
}

void dfs(vector<vector<int>> v, int cnt) 
{
    if (cnt == 5) 
    {
        int tmp = findMaxValue(v);
        res = (res < tmp ? tmp : res);
        return;
    }

    for (int i = 0; i < 4; ++i) 
    {
        dfs(moveVector(v, i), cnt + 1);
    }
}

int main() 
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    
	cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> v[i][j];
    dfs (v, 0);
    cout << res;
    return 0;
}