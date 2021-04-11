#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string s = "";

	cin >> s;

	map<string, int> m;
	for (int i = 0; i < s.length(); i++) {
		string tmp = "";
		for (int j = i; j < s.length(); j++) {
			tmp += s[j];
			m[tmp] = 1;
		}
	}

	cout << m.size();
}
