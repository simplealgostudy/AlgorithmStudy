#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int testCase = 1;
	while (1) {
		int N = 0;
		cin >> N;
		if (N == 0) break;

		map<string, pair<string, bool>> m;
		vector<string> startV;
		for (int i = 0; i < N; i++) {
			string n1, n2;
			cin >> n1 >> n2;

			m[n1] = make_pair(n2, false);
			startV.push_back(n1);
		}

		int answer = 0;
		for (int i = 0; i < startV.size(); i++) {
			if (!m[startV[i]].second) {
				answer++;
				string member = startV[i];
				while (!m[member].second) {
					m[member].second = true;
					member = m[member].first;
				}
			}		
		}

		cout << testCase << ' ' << answer << '\n';
		testCase++;
	}
}
