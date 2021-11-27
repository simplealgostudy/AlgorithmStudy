#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0, M = 0;
	cin >> N >> M;

	vector<string> v;
	for(int i = 0; i < N; i++){
		string str = "";
		cin >> str;
		
		v.push_back(str);
	}

	sort(v.begin(), v.end());
	int answer = 0;

	for (int i = 0; i < M; i++) {
		string ans = "";
		cin >> ans;

		int left = 0, right = v.size() - 1;
		while (left <= right) {
			int idx = (left + right) / 2;

			if (ans < v[idx]) right = idx - 1;
			else if (ans > v[idx]) left = idx + 1;
			
			if (v[idx].substr(0, ans.length()) == ans) {
				answer++;
				break;
			}
		}
	}

	cout << answer;
}
