#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string ques = "";
	cin >> ques;

	stack<char> stk;
	int answer = 0;
	int tmp = 1;

	for (int i = 0; i < ques.length(); i++) {
		if (ques[i] == '(') {
			stk.push(ques[i]);
			tmp *= 2;
		}
		else if (ques[i] == '[') {
			stk.push(ques[i]);
			tmp *= 3;
		}
		else if (ques[i] == ')') {
			if (stk.empty()) {
				answer = 0;
				break;
			}
			else if (stk.top() == '(') {
				stk.pop();
				if (ques[i - 1] == '(') {
					answer += tmp;
				}

				tmp /= 2;
			}
			else {
				answer = 0;
				break;
			}
		}
		else if (ques[i] == ']') {
			if (stk.empty()) {
				answer = 0;
				break;
			}
			else if (stk.top() == '[') {
				stk.pop();
				if (ques[i - 1] == '[') {
					answer += tmp;
				}
				tmp /= 3;
			}
			else {
				answer = 0;
				break;
			}
		}
	}

	if (!stk.empty()) answer = 0;

	cout << answer;
} 
