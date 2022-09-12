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

	stack<int> stk[3];
	vector<pair<int, int>> answer;
	for (int i = 0; i < N; i++) {
		int tmp = 0;
		cin >> tmp;

		stk[0].push(tmp);
	}

	int cur = N;

	while (cur > 0) {
		if (!stk[0].empty()) {
			while (!stk[0].empty()) {
				int tmp = stk[0].top();
				stk[0].pop();
				if (tmp == cur) {					
					answer.push_back(make_pair(1, 3));
					cur--;
				}
				else {
					stk[1].push(tmp);
					answer.push_back(make_pair(1, 2));
				}
			}
		}
		else {
			while (!stk[1].empty()) {
				int tmp = stk[1].top();
				stk[1].pop();
				if (tmp == cur) {
					answer.push_back(make_pair(2, 3));
					cur--;
				}
				else {
					stk[0].push(tmp);
					answer.push_back(make_pair(2, 1));
				}
			}
		}
	}

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << ' ' << answer[i].second << '\n';
	}
	
}
