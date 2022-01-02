#include <bits/stdc++.h>
using namespace std;
#define MAX 1e5+1
int arr[(int)MAX];
int main() {
    int n; 
    scanf("%d", &n);
    int carry = 0, idx = 0, answer = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if (i && arr[i-1] > arr[i]) {
            idx = i;
            carry++;
            if (carry == 2) {
                printf("0");
                return 0;
            }
        }
    }
    if (carry) {
        if (idx == n - 1 || (idx + 1 < n && arr[idx-1] <= arr[idx+1])) ++answer;
        if (idx == 1 || (idx > 1 && arr[idx-2] <= arr[idx])) ++answer;
        printf("%d", answer);
    } else {
        printf("%d", n);
    }
    return 0;
}
