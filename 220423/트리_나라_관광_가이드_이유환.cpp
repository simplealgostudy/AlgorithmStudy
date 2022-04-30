#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int A[200001];
int answer[200001];

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int N = 0;
	cin >> N;	

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		answer[i] = -2;
	}

	answer[A[0]] = -1;
	int k = 0;

	for (int i = 0; i < N; i++) {
		if (answer[A[i]] == -2) {
			answer[A[i]] = A[i - 1];
			if (k < A[i]) k = A[i];
		}
	}

	cout << k + 1 << '\n';
	for (int i = 0; i < k + 1; i++) {
		cout << answer[i] << ' ';
	}
}
