#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int Q = 0;
	cin >> Q;

	map<string, priority_queue<int>> map;
	long long answer = 0;

	for (int i = 0; i < Q; i++) {
		int q = 0;
		cin >> q;

		string name = "";
		cin >> name;

		long long k = 0;
		cin >> k;

		if (q == 1) {
			for (int j = 0; j < k; j++) {
				long long c = 0;
				cin >> c;

				map[name].push(c);
			}
		}
		else {
			for (int j = 0; j < k; j++) {
				if (!map[name].empty()) {
					answer += map[name].top();
					map[name].pop();
				}
				else break;
			}
		}
	}

	cout << answer;
}
