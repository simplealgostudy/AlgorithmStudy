#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool operator<=(const string& a, const string& b) {
	if (a.size() == b.size()) {

		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) return false;
			else if (a[i] < b[i]) return true;
		}

		return true;
	}

	if (a.size() < b.size()) return true;
	else return false;
}

string strNumChange(string n1, string n2) {
	long long tmp = 0;

	string returnVal;

	while (!n1.empty() || !n2.empty() || tmp) {
		if (!n1.empty()) {
			tmp += n1.back() - '0';
			n1.pop_back();
		}
		if (!n2.empty()) {
			tmp += n2.back() - '0';
			n2.pop_back();
		}

		returnVal.push_back((tmp % 10) + '0');
		tmp /= 10;
	}

	reverse(returnVal.begin(), returnVal.end());
	return returnVal;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	vector<string> dp;

	dp.push_back("0");
	dp.push_back("1");
	for (int i = 2; i < 1001; i++) {
		dp.push_back(strNumChange(dp[i - 1], dp[i - 2]));
	}

	while (1) {
		string a, b;

		cin >> a >> b;

		if (a == "0" && b == "0") break;

		int answer = 0;
		for (int i = 2; i < 1001; i++) {
			if (a <= dp[i] && dp[i] <= b) answer++;
		}

		cout << answer << '\n';
	}
}
