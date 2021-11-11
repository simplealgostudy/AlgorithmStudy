#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0;
	cin >> N;

	string s = "";
	cin >> s;

	vector<int> v(27);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}

	stack<long double> stk;
	for (int i = 0; i < s.length(); i++) {
		long double a = 0, b = 0;
		
		if (s[i] == '+') {
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();

			stk.push(a + b);
		}
		else if (s[i] == '-') {
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();

			stk.push(a - b);
		}
		else if (s[i] == '*') {
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();

			stk.push(a * b);
		}
		else if (s[i] == '/') {
			b = stk.top();
			stk.pop();
			a = stk.top();
			stk.pop();

			stk.push(a / b);
		}
		else {
			stk.push(v[s[i] - 65]);
		}

	}

	cout << fixed;
	cout.precision(2);
	cout << stk.top();
}
