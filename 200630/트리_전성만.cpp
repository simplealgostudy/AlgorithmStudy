// https://www.acmicpc.net/problem/1068

#include <iostream>
using namespace std;

int v[50][50];
int cnt = 0, n, del;

void fnd(int m) {
    int chk = 0;
    for(int i = 0; i < n; i++) {
        if (v[m][i] == del)
        {
            v[m][i] = -1;
        }
        if (v[m][i] != -1)
        {
            fnd(v[m][i]);
        }
        if (v[m][i] == -1) 
        {
            chk++;
        }
    }
    if(chk == n)
    {
        cnt++;
        return;
    }
}

int main() {
    fill (&v[0][0], &v[50-1][2], -1);

    cin >> n;
    int t;
    int root;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        if(~t) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (v[t][j] == -1)
                {
                    v[t][j] = i;
                    break;
                }
            }
        } 
        else
        {
            root = i;
        }
    }
    cin >> del;
    if (del == root) {
        cout << 0 << endl;
        return 0;
    }

    fnd(root);

    cout << cnt << endl;

    return 0;
}