#include <iostream>
#include <vector>
using namespace std;

int main()
{	
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string roll = "", angel = "", devil = "";
	cin >> roll >> angel >> devil;

	vector<vector<int>> dpA(101, vector<int>(21, 0));
	vector<vector<int>> dpD(101, vector<int>(21, 0));

	for (int i = 0; i < angel.length(); i++) {
		if (angel[i] == roll[0]) dpA[i][0] = 1;
		if (devil[i] == roll[0]) dpD[i][0] = 1;
	}

	for (int i = 0; i < angel.length(); i++) {
		for (int j = 1; j < roll.length(); j++) {
			if (angel[i] == roll[j]) {
				int cnt = 0;
				for (int z = 0; z < i; z++) {
					cnt += dpD[z][j - 1];
				}
				dpA[i][j] = cnt;
			}
			if (devil[i] == roll[j]) {
				int cnt = 0;
				for (int z = 0; z < i; z++) {
					cnt += dpA[z][j - 1];
				}
				dpD[i][j] = cnt;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < angel.length(); i++) {
		answer += dpA[i][roll.length() - 1];
		answer += dpD[i][roll.length() - 1];
	}
	cout << answer;
}
