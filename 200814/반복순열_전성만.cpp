#include <bits/stdc++.h>
using namespace std;

int sequence[10];

int POW(int i, int n) {
    int ex = 1;
    while(n > 1) {
        if (n & 1) {
            ex *= i;
        }
        i *= i;
        n = n >> 1;
    }
    return i * ex;
}

void make_sequence(int P) {
    for(int i = 1; i <= 9; i++) {
        sequence[i] = POW(i, P);
    }
}

long long SUM(int A) {
    long long sum = 0;
    while(A != 0) {
        sum += sequence[A % 10];
        A /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long A;
    int P;
    cin >> A >> P;
    make_sequence(P);
    map<long long, int> m;
    int cnt = 0;
    while(1) {
        auto sear = m.find(A);
        if(sear != m.end()) {
            cout << sear->second;
            break;
        } else {
            m.insert(make_pair(A, cnt++));
            A = SUM(A);
        }
    }
    
    return 0;
}