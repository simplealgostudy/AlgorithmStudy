#include <iostream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main() {
	stack<pair<int, int>> towers;
	vector<int> answer;
	vector<int> check;

	int testCase = 0;
	cin >> testCase;
	
	int tower = 0;

	for (int i = 0; i < testCase; i++) {
		cin >> tower;
		answer.push_back(0);
		check.push_back(tower);

		if (towers.empty()) {
			towers.push(make_pair(i + 1, tower));
		}
		else {
			while (check[i] > towers.top().second) {
				towers.pop();
				if (towers.empty()) break;
			}
			if (!towers.empty()) answer[i]= towers.top().first;
			towers.push(make_pair(i + 1, tower));
		}	
	}

	for (int i = 0; i < testCase; i++)
		cout << answer[i] << " ";
}
