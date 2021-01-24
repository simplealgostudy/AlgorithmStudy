#include <iostream>
#include <string>
using namespace std;

int main()
{
	string ans;
	cin >> ans;
	
	int count = 0;
	int checkIdx = 0;
	for (int i = 0; i < ans.length(); i++){
		if (ans[i] == ':') {
			count++;
		}
		if (i > 0) {
			if (ans[i - 1] == ':' && ans[i] == ':') {
				checkIdx = i - 1;
			}
		}
	}

	if (count < 7) {
		for (int i = 0; i <= 7 - count - 1; i++) {
			ans.insert(checkIdx + 1, ":");
		}
	}
	else if (count > 7) {
		for (int i = 1; i < ans.length(); i++) {
			if (ans[i - 1] == ':' && ans[i] == ':') {
				ans.erase(i - 1, 1);
			}
		}
	}
	count = 0;
	for (int i = 0; i < ans.length(); i++) {
		count++;

		if (ans[i] == ':' && count < 5) {
			for (int j = 0; j < 5 - count; j++) {
				ans.insert(i - count + 1, "0");
			}
			i += 5 - count;
			count += 5 - count;
		}
		
		if (count == 5) count = 0;
	}

	if (count < 4) {
		for (int i = 0; i < 4 - count; i++) {
			ans.insert(ans.length() - count, "0");
		}	
	}
	cout << ans;
}
