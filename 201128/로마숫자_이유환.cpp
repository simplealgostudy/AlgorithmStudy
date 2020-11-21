#include <iostream>
#include <vector>
using namespace std;

vector<string> romNum = { "I", "V", "X", "L", "C", "D", "M" };
vector<string> romNum2 = { "IV", "IX", "XL", "XC", "CD", "CM" };

vector<int> araNum = { 1, 5, 10, 50, 100, 500, 1000 };
vector<int> araNum2 = { 4, 9, 40, 90, 400, 900 };

string romAnswer = "";

int romAdd(string push, int change) {
	int check = 4001;
	int checkIdx = 0;
	for (int i = 0; i < push.length(); i++) {
		string tmp = "";
		tmp += push[i];
		for (int j = 0; j < romNum.size(); j++) {
			if (tmp.compare(romNum[j]) == 0) {
				if (check >= araNum[j]) {
					check = araNum[j];
					checkIdx = j;
				}
				else check = 4002;
			}
		}

		tmp = "";
		if (check == 4002) {
			change -= araNum[checkIdx];
			tmp += romNum[checkIdx];
			tmp += push[i];

			for (int j = 0; j < romNum2.size(); j++) {
				if (tmp.compare(romNum2[j]) == 0) {
					change += araNum2[j];
				}
			}
		}
		else change += check;

	}

	return change;
}

int araDiv(int push, int check, string romNum) {
	int tmp = 0;
	if (push >= check) {
		tmp = push / check;

		for (int i = 0; i < tmp; i++) {
			romAnswer += romNum;
		}

		push -= tmp * check;
	}

	return push;
}

int main()
{	
	string push1, push2;

	cin >> push1 >> push2;
	int change1 = 0, change2 = 0;

	change1 = romAdd(push1, change1);
	change2 = romAdd(push2, change2);

	int araAnswer = 0;
	araAnswer = change1 + change2;

	cout << araAnswer << endl;

	for (int i = romNum.size() - 1; i >= 0; i--) {
		if (i < romNum.size() - 1) {
			araAnswer = araDiv(araAnswer, araNum2[i], romNum2[i]);
		}
		araAnswer = araDiv(araAnswer, araNum[i] ,romNum[i]);			
	}

	cout << romAnswer;
}
