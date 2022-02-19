#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int R = 0, C = 0;
vector<string> v;
map<string, bool> m;

bool check(int idx) {
	m.clear();
	for (int c = 0; c < C; c++) {
		string str = "";
		for (int r = idx + 1; r < R; r++) {
			str += v[r][c];
		}

		if (!m[str]) m[str] = true;
		else return true;
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> R >> C;
	
	for (int r = 0; r < R; r++) {
		string str = "";
		cin >> str;

		v.push_back(str);
	}

	int start = 0, end = R - 1, mid = 0;
	int answer = R - 1;

	while (start <= end) {
		mid = (start + end) / 2;
		
		if (check(mid)) {
			end = mid - 1;
			if (answer > mid) answer = mid;
		}
		else {
			start = mid + 1;
		}
	}

	cout << answer;
}
