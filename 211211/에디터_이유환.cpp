#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str = "";
	cin >> str;

	stack<char> stk;
	for (int i = 0; i < str.length(); i++) {
		stk.push(str[i]);
	}

	int M = 0;
	cin >> M;

	stack<char> tmp;
	for (int i = 0; i < M; i++) {
		char work = '.';
		cin >> work;

		if (work == 'L') {
			if (!stk.empty()) {
				tmp.push(stk.top());
				stk.pop();
			}		
		}
		else if (work == 'D') {
			if (!tmp.empty()) {
				stk.push(tmp.top());
				tmp.pop();
			}
		}
		else if (work == 'B') {
			if (!stk.empty()) stk.pop();
		}
		else if (work == 'P') {
			char val = '.';
			cin >> val;

			stk.push(val);
		}
	}
	
	string ansTmp = "";
	while (!stk.empty()) {
		ansTmp += stk.top();
		stk.pop();
	}

	string answer = "";
	for (int i = ansTmp.length() - 1; i >= 0; i--) {
		answer += ansTmp[i];
	}

	while (!tmp.empty()) {
		answer += tmp.top();
		tmp.pop();
	}
	cout << answer;
}
