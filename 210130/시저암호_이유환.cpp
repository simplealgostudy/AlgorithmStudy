#include <iostream>
#include <vector>
using namespace std;

vector<int> makeTalbe(string pattern) {
	int patternSize = pattern.size();
	vector<int> table(patternSize, 0);
	int j = 0;
	for (int i = 1; i < patternSize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

vector<int> KMP(string parent, string pattern, vector<int> ans, int idx, vector<int> answer) {
	vector<int> table = makeTalbe(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	int count = 0;

	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				ans[idx]++;
				j = table[j];
			}
			else {
				j++;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == 1) answer.push_back(i);
	}
	return answer;
}

int main() {
	int testCase = 0;
	cin >> testCase;

	for (int t = 0; t < testCase; t++) {
		vector<int> answer;
		string a, w, s;
		cin >> a >> w >> s;
		int pos[200] = {0};		
		for (int i = 0; i < a.size(); ++i) pos[(int)a[i]] = i;
		for (int i = 0; i < a.size(); i++) {
			vector<int> ans(a.size());
			int cnt = 0;
			string temp(s);
			for (int j = 0; j < s.size(); ++j) {
				temp[j] = a[(pos[(int)s[j]] - i + a.size()) % a.size()];
			}
			answer = KMP(temp, w, ans, i, answer);
		}

		if (answer.size() == 0) cout << "no solution";
		else if (answer.size() == 1) cout << "unique: " << answer[0];
		else {
			cout << "ambiguous: ";
			for (int i = 0; i < answer.size(); i++) {
				cout << answer[i] << " ";
			}
		}
		cout << endl;
		
	}
}
