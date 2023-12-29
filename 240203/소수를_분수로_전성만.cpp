#include <bits/stdc++.h>
using namespace std;

void cal(string& str)
{
  int n = str.size();
  long long nump = 0;
  for (int idx = 2; idx < n; idx++)
  {
    nump *= 10;
    nump += (str[idx]-'0');
  }
  long long num = 1;
  for (int i =0 ; i < n-2; i++)
    num *= 10;
  long long gcd = __gcd(num, nump);
  cout << (nump/gcd) << '/' << (num/gcd) << '\n';
}

void calLoop(string& str)
{
  long long loopNum = 0;
  long long nLoopNum = 0;
  long long allNum = 0;
  int n = str.size();
  bool bLoop = false;
  int nCnt = 0;
  int nLoopCnt = 0;
  for (int idx = 2; idx < n; idx++)
  {
    if (str[idx] == '(' || str[idx] == ')')
    {
      bLoop = true;
      continue;
    }
    nCnt++;
    allNum *= 10;
    allNum += str[idx] -'0';
    if (false == bLoop)
    {
      nLoopNum *= 10;
      nLoopNum += str[idx] - '0';
    }
    else
      nLoopCnt++;
  }
  allNum -= nLoopNum;
  long long deno = 0;
  for (int i = 0; i < nLoopCnt;i++)
  {
    deno *= 10;
    deno += 9;
  }
  if (nCnt - nLoopCnt != 0)
    for (int i = 0; i < nCnt - nLoopCnt;i++)
      deno *= 10;
  long long gcd = __gcd(allNum, deno);
  cout << (allNum/gcd) << '/' << (deno/gcd) <<'\n';

}

void sol() {
  string str;
  cin >> str;
  if (str.back() == ')')
    calLoop(str);
  else
    cal(str);
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    sol();
  }
  return 0;
}
