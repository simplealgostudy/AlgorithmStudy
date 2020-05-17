#include <iostream>
#include <stack>
 
using namespace std;
int main()
{
    stack<int> s;
    int size, value;
    string order;
 
    cin >> size;
 
    while (size != 0)
    {
        cin >> order;
        if (order == "size")
        {
            cout << s.size() << endl;
            size--;
            continue;
        }
        else if (order == "empty")
        {
            cout << s.empty() << endl;
            size--;
            continue;
        }
        else if (order == "top")
        {
            if(s.empty()==1){
                cout<<-1<<endl;
                size--;
                continue;
            }
            cout << s.top() << endl;
            size--;
            continue;
        }
        else if (order == "pop")
        {
            if (s.empty() == 1)
            {
                cout << -1 << endl;
                size--;
                continue;
            }
            else
            {
                cout<<s.top()<<endl;
                s.pop();
                size--;
                continue;
            }
        }
        else if (order == "push")
        {
            cin >> value;
            s.push(value);
            size--;
            continue;
        }
    }
    return 0;
}
