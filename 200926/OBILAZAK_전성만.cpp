#include <bits/stdc++.h>
using namespace std;
int arr[1025];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int k; cin >> k;
    for (int i = 1; i <= (1<<k)-1; cin>>arr[i], i++);
    for (int i = k-1; i >= 0; i--) {
        for (int j = 1<<i; j <= 1<<k; j+=(1<<i+1)) {
            cout << arr[j] << ' ';
        }
        cout << '\n';
    }
}