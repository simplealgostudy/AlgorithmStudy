#include <bits/stdc++.h>
using namespace std;

class dis
{
public:
    string name;
    map<string, dis*> m;
    dis* next;
    dis()
    {}
};

vector<string> strsplit(string str)
{
    stringstream ss(str);
    string tmp;
    vector<string> ret;
    while (getline(ss, tmp, '\\'))
    {
        ret.push_back(tmp);
    }
    return ret;
}

void print(dis* node, int deep)
{
    for (auto it = node->m.begin(); it != node->m.end(); it++)
    {
        cout << string(deep, ' ') << it->first << '\n';
        if (! it->second->m.empty())
        {
            print(it->second, deep + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    dis *start = new dis();
    while (n--)
    {
        string str; cin >> str;
        vector<string> vecs = strsplit(str);
        dis *cur = start;
        for (int i = 0; i < vecs.size(); i++)
        {
            dis* next = new dis();
            if (cur->m.find(vecs[i]) == cur->m.end())
            {
                next->name = vecs[i];
                cur->m[vecs[i]] = next;
                next = cur->m[vecs[i]];
            }
            next = cur->m[vecs[i]];
            cur->next = next;
            cur = next; 
        }
    }
    print(start, 0);
    return 0;
}
