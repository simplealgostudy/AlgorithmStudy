#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class LinkedQueue
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
    };
    Node *head, *rear;
    int length = 0;

    //const가 뒤에 붙은 함수는 접근 함수를 나타냄!
    //접근 함수란 수정 함수와 달리 클래스 데이터를 수정하지 않는 함수를 말함!
public:
    int size();
    bool empty() const;
    void push();
    int pop();
    int front() const;
    int back() const;
};
int LinkedQueue::size()
{
    if (length < 0)
        length = 0;
    return length;
}
bool LinkedQueue::empty() const
{
    return length == 0;
}
void LinkedQueue::push()
{
    int value;
    scanf("%d\n", &value);
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    if (empty())
    {
        head = rear = node;
    }
    else
    {
        rear->next = node;
        rear = rear->next;
    }
    length++;
}
int LinkedQueue::pop()
{
    if (empty())
    {
        return -1;
        length--;
    }
    else
    {
        Node* delNode = head;
        int temp = delNode->data;
        head = delNode->next;
        free(delNode);
        length--;
        return temp;
    }
}
int LinkedQueue::front() const
{
    if (empty())
        return -1;
    else
        return head->data;
}
int LinkedQueue::back() const
{
    if (empty())
        return -1;
    else
        return rear->data;
}
int main()
{
    LinkedQueue q;
    int orderSize;
    char order[6];
    vector<int> result;
    scanf("%d", &orderSize);

    while (orderSize--)
    {
        scanf("%s", &order);
        switch (order[0])
        {
        case 'p':
            if (order[1] == 'u')
                q.push();
            else
                result.push_back(q.pop());
            break;
        case 's':
            result.push_back(q.size());
            break;
        case 'e':
            result.push_back(q.empty());
            break;
        case 'f':
            result.push_back(q.front());
            break;
        case 'b':
            result.push_back(q.back());
            break;
        }
    }
    for (int i = 0; i < result.size(); i++)
        printf("%d\n", result[i]);
    return 0;
}