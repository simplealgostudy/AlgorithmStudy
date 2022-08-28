#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N = 0;

	cin >> N;

	vector<pair<string, string>> v;
	for (int t = 0; t < N; t++) {
		string str = "";
		cin >> str;

		string tmp = "";
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'k') tmp += 'c';
			else if (i + 1 < str.length() && (str[i] == 'n' && str[i + 1] == 'g')) {
				tmp += "n~";
				i++;
			}
			else tmp += str[i];			
		}

		v.push_back(make_pair(tmp, str));
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < N; i++) {
		cout << v[i].second << '\n';
	}
	
}
