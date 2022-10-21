#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v;
int N = 0;
int answer = 0;

void dfs(vector<int> v, int cnt) {
	if (v.size() == 2) {
		if(answer < cnt) answer = cnt;
		return;
	}

	for (int i = 1; i < v.size() - 1; i++) {
		vector<int> tmpV = v;
		int tmp = cnt + (v[i - 1] * v[i + 1]);
		tmpV.erase(tmpV.begin() + i);
		dfs(tmpV, tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int w = 0;
		cin >> w;

		v.push_back(w);
	}

	dfs(v, 0);

	cout << answer;
}
