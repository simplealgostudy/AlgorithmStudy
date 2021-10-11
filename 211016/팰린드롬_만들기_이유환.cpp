#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string str) {	
	int size = str.length();

	for (int i = 0; i < size / 2; i++) {
		if (str[i] != str[size - i - 1]) return false;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	string str = "";

	cin >> str;

	int answer = str.length();

	for (int i = 0; i < str.length(); i++) {
		if (isPalindrome(str.substr(i))) {
			answer += i;
			break;
		}
	}
	
	cout << answer;
}
