#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    int x;
    int y;
    int idx;
    Node *left;
    Node *right;
};

vector<int> posC(const Node *node, vector<int> &po) {
    if (node->left != NULL) {
        posC(node->left, po);
    }
    if (node->right != NULL) {
        posC(node->right, po);
    }
    po.emplace_back(node->idx);

    return po;
}
vector<int> preC(const Node *node, vector<int> &pr) {
    pr.emplace_back(node->idx);
    if (node->left != NULL) {
        preC(node->left, pr);
    }
    if (node->right != NULL) {
        preC(node->right, pr);
    }

    return pr;
}

bool sort_(vector<int> a, vector<int> b) {
    if (a[1] == b[1]) {
        return a[0] < b[0];
    }
    else {
        return a[1] > b[1];
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for (int i = 0; i < nodeinfo.size(); i++) {
        nodeinfo[i].emplace_back(i+1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), sort_);

    Node node = {nodeinfo[0][0], nodeinfo[0][1], nodeinfo[0][2], NULL, NULL};
    Node * iter;

    for (int i = 1; i < nodeinfo.size(); i++) {
        iter = & node;
        while(1) {
            if (iter->x > nodeinfo[i][0]) {
                if (iter->left == NULL) {
                    iter->left = new Node{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], NULL, NULL};
                    break;
                }
                else {
                    iter = iter->left;
                }
            }
            else {
                if (iter->right == NULL) {
                    iter->right = new Node{nodeinfo[i][0], nodeinfo[i][1], nodeinfo[i][2], NULL, NULL};
                    break;
                }
                else {
                    iter = iter->right;
                }
            }
        }
    }
    vector <int> pr;
    vector <int> po;
    answer.emplace_back(preC(&node, pr));
    answer.emplace_back(posC(&node, po));

    return answer;
}