#include <iostream>
int n, a, b, m[100001]; 
int main() {
    scanf("%d",&n);
    while(--n) {
        scanf("%d%d",&a,&b);
        m[a]++, m[b]++;
    }
    scanf("%d",&n);
    while(n--) {
        scanf("%d%d",&a,&b);
        printf("%s\n",((a==2||!(m[b]==1||m[b]==0))?"yes":"no"));
    }
}
