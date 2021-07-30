#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9;
int main() {
    // freopen("execute.in", "r", stdin);
    // freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string input;
    map<string, int> m;
    m["NUM"]=1;m["POP"]=2;m["INV"]=3;m["DUP"]=4;m["SWP"]=5;m["ADD"]=6;m["SUB"]=7;m["MUL"]=8;m["DIV"]=9;m["MOD"]=10;m["END"]=11;m["QUIT"]=12;
    vector<long long> v;
    bool err = false;
    vector<string> vstr;
    while(1) {
        vstr.clear();
        cin >> input;
        if (!input.compare("QUIT")) {
            return 0;
        } else {
            vstr.push_back(input);
            if (!input.compare("NUM")) {
                cin >> input;
                vstr.push_back(input);
            }
            if (input.compare("END")) {
                while (1) {
                    cin >> input;
                    if (!input.compare("END")) {
                        vstr.push_back(input);
                        break;
                    }
                    vstr.push_back(input);
                    if (!input.compare("NUM")) {
                        cin >> input;
                        vstr.push_back(input);
                    }
                }
            }
        }
        int testcase; cin >> testcase;
        while(testcase--) {
            err = false;
            int testint; cin >> testint;
            v.push_back(testint);
            int testC = 0;
            while(testC < vstr.size()){
                if (err && m[vstr[testC]] != 11) {
                    if (m[vstr[testC]] == 1) testC++;
                    testC++;
                    continue;
                }
                switch(m[vstr[testC++]]) {
                    case 1: {
                        v.push_back(stoi(vstr[testC++]));
                        break;
                    }
                    case 2: {
                        if (!v.size()) {
                            err = true;
                            break;
                        }
                        v.pop_back();
                        break;
                    }
                    case 3: {
                        if (!v.size()) break;
                        v.back() = -v.back();
                        break;
                    }
                    case 4: {
                        if (!v.size()) break;
                        v.push_back(v.back());
                        break;
                    }
                    case 5: {
                        if (v.size() < 2) {
                            err = true;
                            break;
                        }
                        long long t1 = v.back();
                        v.pop_back();
                        long long t2 = v.back();
                        v.pop_back();
                        v.push_back(t1);
                        v.push_back(t2);
                        break;
                    }
                    case 6: {
                        if (v.size() < 2) {
                            err = true;
                            break;
                        }
                        long long t1 = v.back();
                        v.pop_back();
                        long long t2 = v.back();
                        v.pop_back();
                        if (abs(t1 + t2) > MAX) {
                            err = true;
                            break;
                        } else {
                            v.push_back(t1 + t2);
                        }
                        break;
                    }
                    case 7: {
                        if (v.size() < 2) {
                            err = true;
                            break;
                        }
                        long long t1 = v.back();
                        v.pop_back();
                        long long t2 = v.back();
                        v.pop_back();
                        if (abs(t2 - t1) > MAX) {
                            err = true;
                            break;
                        } else {
                            v.push_back(t2 - t1);
                        }
                        break;
                    }
                    case 8: {
                        if (v.size() < 2) {
                            err = true;
                            break;
                        }
                        long long t1 = v.back();
                        v.pop_back();
                        long long t2 = v.back();
                        v.pop_back();
                        if (abs(t1 * t2) > MAX) {
                            err = true;
                            break;
                        } else {
                            v.push_back(t1 * t2);
                        }
                        break;
                    }
                    case 9: {
                        if (v.size() < 2) {
                            err = true;
                            break;
                        }
                        bool min = false;
                        long long t1 = v.back();
                        v.pop_back();
                        long long t2 = v.back();
                        v.pop_back();
                        if (!t1) {
                            err = true;
                            break;
                        }
                        if ((t1>0&&t2<0)||(t1<0&&t2>0)) {
                            min = true;
                        }
                        if (abs(t2) / abs(t1) > MAX) {
                            err = true;
                            break;
                        } else {
                            long long tmp = abs(t2) / abs(t1);
                            if (min) v.push_back(-tmp);
                            else v.push_back(tmp);
                        }
                        break;
                    }
                    case 10: {
                        if (v.size() < 2) {
                            err = true;
                            break;
                        }
                        bool min = false;
                        long long t1 = v.back();
                        v.pop_back();
                        long long t2 = v.back();
                        v.pop_back();
                        if (!t1) {
                            err = true;
                            break;
                        }
                        if (t2 < 0) {
                            min = true;
                        }
                        if (abs(t2) % abs(t1) > MAX) {
                            err = true;
                            break;
                        } else {
                            long long tmp = abs(t2) % abs(t1);
                            if (min) v.push_back(-tmp);
                            else v.push_back(tmp);
                        }
                        break;
                    }
                    case 11: {
                        if (err || v.size() != 1) {
                            cout << "ERROR" << '\n';
                        } else {
                            cout << v.back() << '\n';
                        }
                        err = false;
                        v.clear();
                        break;
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}