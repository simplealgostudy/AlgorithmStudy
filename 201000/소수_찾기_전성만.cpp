#include <bits/stdc++.h>
// 참고 : https://www.tutorialspoint.com/print-all-the-combinations-of-a-string-in-lexicographical-order-in-cplusplus
using namespace std;
set<int> s;

void printResult(char* result, int len)
{
	string str = "";
	for (int i = 0; i <= len; i++) str += result[i];
	int n = stoi(str);
	s.insert(n);
}

void findstringCombination(char result[], char str[], int count[], int level, int size, int length)
{
	if (level == size) return;
	for (int i = 0; i < length; i++)
	{
		if (count[i] == 0) continue;
		count[i]--;
		result[level] = str[i];
		printResult(result, level);
		findstringCombination(result, str, count, level + 1, size, length);
		count[i]++;
	}
}

void printCharCombination(string str)
{
	map<char, int> mp;
	for (int i = 0; i < str.size(); i++)
	{
		if (mp.find(str[i]) != mp.end())
			mp[str[i]] = mp[str[i]] + 1;
		else
			mp[str[i]] = 1;
	}
	char* input = new char[mp.size()];
	int* count = new int[mp.size()];
	char* result = new char[str.size()];
	map<char, int>::iterator it = mp.begin();
	int i = 0;
	for (it; it != mp.end(); it++) {
		input[i] = it->first;
		count[i] = it->second;
		i++;
	}
	int length = mp.size();
	int size = str.size();
	findstringCombination(result, input, count, 0, size, length);
}

bool is_Prime(int n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	for (int i = 2; i <= sqrt(n); i++) if (!(n % i)) return false;
	return true;
}

int solution(string numbers)
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	printCharCombination(numbers);
	set<int>::iterator iter;
	int answer = 0;
	for (iter = s.begin(); iter != s.end(); ++iter) if (is_Prime(*iter)) answer++;
	return answer;
}