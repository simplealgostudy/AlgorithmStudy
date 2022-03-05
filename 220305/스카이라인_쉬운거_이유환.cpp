#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int n = 0;
	cin >> n;

	int answer = 0;
	stack<int> stk;

	for (int i = 0; i < n; i++) {
		int a = 0, b = 0;
		cin >> a >> b;

		while (!stk.empty() && stk.top() > b) {
			answer++;
			stk.pop();
		}

		if (stk.empty() || stk.top() != b) {
			stk.push(b);
		}
	}

	while (!stk.empty() && stk.top() > 0) {
		answer++;
		stk.pop();
	}

	cout << answer;
}
