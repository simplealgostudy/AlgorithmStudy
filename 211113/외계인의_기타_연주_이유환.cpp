#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	stack<int> stk[7];

	int N = 0, P = 0;
	cin >> N >> P;

	int answer = 0;
	for (int i = 0; i < N; i++) {
		int n = 0, p = 0;
		cin >> n >> p;

		if (stk[n].empty()) {
			stk[n].push(p);
			answer++;
		}
		else if (stk[n].top() > p) {
			while (!stk[n].empty() && stk[n].top() > p) {
				stk[n].pop();
				answer++;
			}
			if (!stk[n].empty() && stk[n].top() != p) {

				stk[n].push(p);
				answer++;
			}
			else if (stk[n].empty()) {
				stk[n].push(p);
				answer++;
			}
		}
		else if (stk[n].top() < p) {
			stk[n].push(p);
			answer++;
		}
	}

	cout << answer;
}
