#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int T = 0;
	cin >> T;

	

	for (int testCase = 0; testCase < T; testCase++) {
		string A = "", B = "";
		cin >> A >> B;

		vector<int> av;
		vector<int> bv;
		
		for (int i = 0; i < A.length(); i++) {
			if (A[i] == 'a') av.push_back(i);
		}
		for (int i = 0; i < B.length(); i++) {
			if (B[i] == 'a') bv.push_back(i);
		}

		int answer = 0;
		for (int i = 0; i < av.size(); i++) {
			answer += abs(av[i] - bv[i]);
		}

		cout << answer << '\n';
	}
}
