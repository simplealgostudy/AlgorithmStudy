#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n, ans = 0; 
    scanf("%d", &n);
    stack<int> stk;
    stk.push(0);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        while (!stk.empty()&&stk.top() >= y) {
            if (stk.top() > y) ans++;
            stk.pop();
        }
        stk.push(y);
    }
    printf("%d", ans+stk.size()-1);
    return 0;
}
