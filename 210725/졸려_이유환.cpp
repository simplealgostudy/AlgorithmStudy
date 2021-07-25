#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	
	int X = 0;
	cin >> X;

	string str = "";
	cin >> str;

	vector<string> v;
	v.push_back(str);

	string check = str;
	int idx = X;
	if (str.length() == 1) cout << str;
	else {
		while (1) {
			string tmp = "";
			int end = 0;

			for (int i = 0; i < str.length(); i += 2) {
				tmp += check[i];
				end = i;
			}
			if (str.length() % 2 == 0) tmp += check[str.length() - 1];

			for (int i = end - 1; i >= 0; i -= 2) {
				tmp += check[i];
			}
			check = tmp;

			if (check == str) break;
			else v.push_back(check);
		}

		cout << v[X % v.size()];
	}
}
