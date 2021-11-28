#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N = 0;
	cin >> N;
	char check;
	check = cin.get(); //getline 할 때 바로 한 줄 먹히는걸 방지하는 구문

	for (int testCase = 0; testCase < N; testCase++) {		
		string t = "";
		getline(cin, t);

		long answer = 1;
		int depth = 0;
		int maxDepth = 0;

		if (t == "" || t == " ") cout << answer << '\n';
		else {
			for (int i = 0; i < t.length(); i++) {
				if (t[i] == '[') {
					depth++;
					maxDepth = max(maxDepth, depth);
				}
				else depth--;
			}

			for (int i = 0; i < maxDepth; i++) {
				answer *= 2;
			}
			cout << answer << '\n';
		}	
	}	
}
