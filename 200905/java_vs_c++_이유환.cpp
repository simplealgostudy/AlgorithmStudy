#include <iostream>
#include <vector>
using namespace std;

int main() {
	string input;
	
	cin >> input;
	int size = input.length();
	int i = 1;
	bool check1 = 0, check2 = 0;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] == '_') check1 = 1;
		if (isupper(input[i])) check2 = 1;
	}

	if (check1 == 1 && check2 == 1) {
		input = "Error!";
	}
	else if (check1 == 1 && check2 == 0 && input[0] == '_') {
		input = "Error!";
	}
	else if (check1 == 1 && check2 == 0 && input[input.length() - 1] == '_') {
		input = "Error!";
	}
	else if (check1 == 0 && check2 == 1 && isupper(input[0])) {
		input = "Error!";
	}
	else {
		while (i < size) {
			if (isupper(input[i]) && input[i] != '_') {
				size++;
				input[i] = tolower(input[i]);
				input.insert(i, "_");
			}
			else if (input[i] == '_' && !isupper(input[i])) {
				if (input[i + 1] == '_') {
					input = "Error!";
					break;
				}
				size--;
				char tmp = toupper(input[i + 1]);
				string add = "";
				add += tmp;

				input.replace(i, 2, add);
			}
			i++;
		}
	}
	
	cout << input << endl;
}