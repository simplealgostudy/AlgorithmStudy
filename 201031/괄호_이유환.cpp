#include<iostream>
using namespace std;
//카탈란 수 활용

int main(void)
{
	long long dp[2501];
	dp[0] = 1;
	dp[1] = 1;

	
	for (int i = 2; i <= 2500; i++) {
		dp[i] = 0;
		for (int j = 0; j < i; j++) {		
			dp[i] += ((dp[j]) * (dp[i - 1 - j])) % 1000000007;
		}
		dp[i] %= 1000000007;
	}
	int t = 0;
	int l = 0;
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> l;
		if (l % 2 != 0) cout << 0 << endl;
		else {
			cout << dp[l / 2] << endl;
		}
	}
}
