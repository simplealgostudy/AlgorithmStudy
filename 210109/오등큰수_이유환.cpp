#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int n = 0;
	int max = 1000001;
	cin >> n;
	
	vector<int> answer;
	stack<int> stk;
	stack<int> check_stk;
	
	int* check = new int[max];
	
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;
		stk.push(a);
		check[a]++;
	}

	bool sw = false;
	int idx = 0;
	while(!stk.empty()) {
		if (check_stk.empty()) {
			check_stk.push(stk.top());
			answer.push_back(-1);
		}
		else if (check[stk.top()] < check[check_stk.top()]) {
			answer.push_back(check_stk.top());
			check_stk.push(stk.top());
		}
		else {
			while (!check_stk.empty() && check[stk.top()] >= check[check_stk.top()]) {
				check_stk.pop();
			}
			if (check_stk.empty()) {
				answer.push_back(-1);
				check_stk.push(stk.top());
			}
			else {
				answer.push_back(check_stk.top());
				check_stk.push(stk.top());
			}
		}
		stk.pop();
	}

	for (int i = answer.size() - 1; i >= 0; i--) {
		cout << answer[i] << " ";
	}
	delete[] check;
}
