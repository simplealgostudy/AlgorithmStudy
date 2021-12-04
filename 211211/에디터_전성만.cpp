#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    char val;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(){}
    Node(char val) : val(val){}
};
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    string str; cin >> str;
    Node *head = new Node('-');
    Node *cur = head;
    for (auto c : str) {
        Node *tmp = new Node(c);
        tmp->prev = cur;
        cur->next = tmp;
        cur = cur->next;
    }

    int n = str.size(), m; cin >> m;
    while (m--) {
        char chr; cin >> chr;
        switch (chr) {
            case 'P': {
                char c; cin >> c;
                if (head == nullptr) {
                    head = new Node();
                    cur = head;
                } else {
                    Node *tmp = new Node(c);
                    tmp->prev = cur;
                    if (cur->next != nullptr) {
                        Node *ne = cur->next;
                        tmp->next = ne;
                        ne->prev = tmp;
                    }
                    cur->next = tmp;
                    cur = cur->next;
                }
                break;
            }
            case 'L': {
                if (cur->prev != nullptr) cur = cur->prev;
                break;
            }
            case 'D': {
                if (cur->next != nullptr) cur = cur->next;
                break;
            }
            case 'B': {
                if (cur->prev != nullptr) {
                    Node * pr = cur->next;
                    cur = cur->prev;
                    cur->next = pr;
                    if (pr != nullptr) pr->prev = cur;
                }
            }
        }
    }
    for (Node* it = head->next; it != nullptr; it = it->next) {
        cout << it->val;
    }
    return 0;
}