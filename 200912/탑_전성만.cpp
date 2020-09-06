#include <bits/stdc++.h>
using namespace std;
int arr[500001];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin>>n;
    int max_p = 0;
    map<int, int> mp;
    stack<int> stk;
    arr[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp.insert({arr[i], i});
    }
    for (int i = 1; i <= n; i++) {
        if(!stk.empty()) {
            if(arr[max_p] < arr[i]) {
                cout << 0 << ' ';
                max_p = i;
                stk.push(arr[i]);
            } else {
                while(!stk.empty() && stk.top() < arr[i]) {
                    stk.pop();
                }
                if(stk.empty()) {
                    stk.push(arr[i]);
                    max_p = 1;
                    cout << 0 << ' ';
                } else {
                    cout << mp[stk.top()] << ' ';
                    stk.push(arr[i]);
                }
            }
        } else {
            stk.push(arr[i]);
            max_p = 1;
            cout << 0 << ' ';
        }
    }
    return 0;
}