#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int main()
{
	vector<int> flipV[9] = {
	{0, 1, 3}, {0, 1, 2, 4}, {1, 2, 5},
	{0, 3, 4, 6}, {1, 3, 4, 5, 7}, {2, 4, 5, 8},
	{3, 6, 7}, {4, 6, 7, 8}, {5, 7, 8}
	};

	int t = 0;
	cin >> t;

	for (int testCase = 0; testCase < t; testCase++) {
		int answer = 1;
		string input = "";
		for (int i = 0; i < 3; i++) {
			string tmp = "";
			cin >> tmp;
			
			input += tmp;
		}
		
		if (input.compare(".........") != 0) {
			queue<string> q;
			set<string> check;
			q.push(".........");
			check.insert(".........");

			bool sw = false;
			while (!q.empty()) {
				int size = q.size();
				while (size--) {
					string qTmp = q.front();
					q.pop();

					for (int i = 0; i < 9; i++) {
						string tmp = qTmp;
						for (int j = 0; j < flipV[i].size(); j++) {
							if (tmp[flipV[i][j]] == '.') tmp[flipV[i][j]] = '*';
							else tmp[flipV[i][j]] = '.';
						}

						if (check.find(tmp) != check.end()) continue;
						if (tmp.compare(input) == 0) {
							sw = true;
							break;
						}
						q.push(tmp);
						check.insert(tmp);
					}

					if (sw == true) break;
				}
				if (sw == true) break;
				answer++;
			}

		}
		else answer = 0;

		 cout << answer << endl;
	}
}
