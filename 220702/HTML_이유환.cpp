#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	bool sw = false;
	string tag = "";
	string answer = "";
	int cnt = 0;

	string str = "";
	while (cin >> str) {
		
		if (str == "<br>") {
			answer += '\n';
			cnt = 0;
		}
		else if (str == "<hr>") {
			if (!cnt) {
				for (int i = 0; i < 80; i++) answer += '-';
				answer += '\n';
			}
			else {
				cnt = 0;
				answer += '\n';
				for (int i = 0; i < 80; i++) answer += '-';
				answer += '\n';
			}
		}
		else {
			int len = str.length();

			if (!cnt) {
				cnt = len;
				answer += str;
				sw = true;
			}
			else if (cnt + len + 1 <= 80) {
				if (sw) {
					answer += ' ';
					cnt++;
				}

				cnt += len;
				answer += str;

				if (cnt == 80) {
					answer += '\n';
					cnt = 0;
					sw = false;
				}

			}
			else {
				answer += '\n';
				cnt = len;
				sw = true;
				answer += str;
			}
		}		
	}

	cout << answer;
}
