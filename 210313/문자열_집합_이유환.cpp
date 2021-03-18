#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	vector<string> v;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		cin >> tmp;
		
		v.push_back(tmp);
	}

	map<string, int> check;
	for (int i = 0; i < m; i++) {
		string tmp = "";
		cin >> tmp;

		check[tmp]++;
	}

	int answer = 0;
	for (int i = 0; i < v.size(); i++) {
		answer += check[v[i]];
	}

	cout << answer;
}
