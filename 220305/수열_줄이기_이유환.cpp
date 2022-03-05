#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int n = 0;
	cin >> n;

	long long answer = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		int a = 0;
		cin >> a;

		if (i == 0) tmp = a;
		else {
			answer += max(tmp, a);
			tmp = a;
		}
		
	}

	cout << answer;
}
