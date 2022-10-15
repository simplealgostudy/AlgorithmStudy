#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string a, b = "";

int search(map<string,string> m, string node, string target) {
	int answer = 0;

	while (m[node] != "") {
		if (m[node] == target) {
			answer = 1;
			break;
		}
		node = m[node];
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int N = 0;
	cin >> N;

	map<string, string> m;
	for (int i = 0; i < N - 1; i++) {
		string c = "";
		cin >> c;
		
		string p = "";
		cin >> p;

		m[c] = p;
	}
	
	cin >> a >> b;

	int answer = 0;
	
	answer = search(m, a, b);
	if(answer != 1) answer = search(m, b, a);
	
	cout << answer;
}
