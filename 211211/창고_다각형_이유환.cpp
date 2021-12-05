#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N = 0, maxT = 0, maxIdx = 0;
	cin >> N;

	vector<int> v(1001);
	for (int i = 0; i < N; i++) {
		int l = 0, h = 0;
		cin >> l >> h;

		if (maxT < h) {
			maxT = h;
			maxIdx = l;
		}

		v[l] = h;
	}

	int answer = 0;

	int maxL = 0;
	for (int i = 0; i <= maxIdx; i++) {
		maxL = max(maxL, v[i]);
		answer += maxL;
	}

	int maxR = 0;
	for (int i = v.size() - 1; i > maxIdx; i--) {
		maxR = max(maxR, v[i]);
		answer += maxR;
	}

	cout << answer;
}
