#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	string S, E, Q;
	cin >> S >> E >> Q;

	string S1 = S.substr(0, 2);
	string S2 = S.substr(3);
	int start = stoi(S1 + S2); 

	string E1 = E.substr(0, 2);
	string E2 = E.substr(3);
	int end = stoi(E1 + E2);

	string Q1 = Q.substr(0, 2);
	string Q2 = Q.substr(3);
	int quit = stoi(Q1 + Q2);

	int answer = 0;
	string T, N;
	map<string, int> m;
	while (!cin.eof()) {	
		cin >> T >> N;
		string T1 = T.substr(0, 2);
		string T2 = T.substr(3);
		int time = stoi(T1 + T2);

		if (time <= start && m[N] == 0) m[N]++;
		else if (time >= end && time <= quit && m[N] == 1) {
			m[N]++;
		}

		if (m[N] == 2) {
			answer++;
			m[N] = -1;
		}
	}
	
	cout << answer;
}
