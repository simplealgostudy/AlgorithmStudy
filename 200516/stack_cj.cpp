#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int main()
{
    stack<int> s;
    int top = -1;
    int n = 0;

    while (!((n >= 1) && (n <= 10000))) {
        cin >> n;
    }

    for (int i = 0; i < n; i++) {
        char str[5];
        cin >> str;
        if (!strcmp(str, "push")) {
            int x;
            cin >> x;
            s.push(x);
        }
        else if (!strcmp(str, "top")) {
            if (s.empty())
                cout << "-1" << endl;
            else
                cout << s.top() << endl;
        }
        else if (!strcmp(str, "pop")) {
            if (s.empty())
                cout << "-1" << endl;
            else {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (!strcmp(str, "empty")) {
            if (s.empty())
                cout << "1" << endl;
            else
                cout << "0" << endl;
        }
        else if (!strcmp(str, "size")) {
            cout << s.size() << endl;
        }
    }
}
