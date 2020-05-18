#include <stdio.h>

int stk[2000001];
char command[6];

int main() {
    int N;
    scanf("%d", &N);
int front = 0, back = 0, size=0;
    while(N--) {
        size = back - front;
        scanf("%s", command);
        switch(command[0]){
        case 'p':
            if(command[1] == 'u'){
                scanf("%d", &stk[back++]);
            } else{
                printf("%d\n", size?stk[front]:-1);
                if(size) front++;
            }
            break;
        case 's':
            printf("%d\n", size);
            break;
        case 'e':
            printf("%d\n", size?0:1);
            break;
        case 'f':
            printf("%d\n", size?stk[front]:-1);
            break;
        case 'b':
            printf("%d\n", size?stk[back-1]:-1);
            break;
        }
    }

    return 0;
}