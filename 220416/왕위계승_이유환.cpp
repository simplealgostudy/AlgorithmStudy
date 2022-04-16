#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, double> dm;
map<string, vector<string>> pm;

double dfs(string name) {
	if (pm[name].empty()) {
		return dm[name];
	}
	else {
		dm[name] = (dfs(pm[name][0]) + dfs(pm[name][1])) / 2;
		return dm[name];
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0, M = 0;
	string king;

	cin >> N >> M;
	cin >> king;
	
	dm[king] = 1;
	for (int i = 0; i < N; i++) {
		string son, p1, p2;
		cin >> son >> p1 >> p2;

		pm[son].push_back(p1);
		pm[son].push_back(p2);
	}

	string answerN = "";
	string answerD = "";
	double max = 0;
	for (int i = 0; i < M; i++) {
		string name;
		cin >> name;

		double cnt = dfs(name);
		if (cnt > max) {
			max = cnt;
			answerN = name;
		}

	}

	cout << answerN;
}
