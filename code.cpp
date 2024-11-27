#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct LinkedList
{
    Node *head;
    Node *tail;
};
// struct TwoNode
// {
//     Node* first;
//     Node* second;
// };

Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = nullptr;
    return p;
}

void addNewNode(LinkedList &list, int x)
{
    Node *p = createNode(x);
    if (list.head == nullptr)
    {
        list.head = p;
        list.tail = p;
    }
    else
    {
        list.tail->next = p;
        list.tail = p;
    }
}

void insertHead(LinkedList &list, int x)
{
    Node *p = createNode(x);
    if (list.head == nullptr)
    {
        list.head = p;
        list.tail = p;
    }
    else
    {
        p->next = list.head;
        list.head = p;
    }
}
void rmAfterNode(Node *p)
{
    if (!p->next)
    {
        return;
    }
    // Node* tmp = p->next;
    p->next = p->next->next;
    // delete tmp;
}
void rmAfterKElements(Node *point, int k)
{
    if (!k)
    {
        return;
    }
    Node *curBlock = point;
    for (int i = 0; i < k - 1; i++)
    {
        curBlock = curBlock->next;
    }
    rmAfterNode(curBlock);
}

void reverseList(LinkedList &list)
{
    if (list.head == nullptr)
    {
        return;
    }
    LinkedList tmp;
    tmp.head = nullptr;
    tmp.tail = nullptr;
    Node *curBlock = list.head;
    while (curBlock != nullptr)
    {
        insertHead(tmp, curBlock->data);
        curBlock = curBlock->next;
    }
    list = tmp;
}
void dispList(LinkedList list)
{
    Node *curBlock = list.head;
    while (curBlock != nullptr)
    {
        cout << curBlock->data << " ";
        curBlock = curBlock->next;
    }
    cout << endl;
}

void rmDuplicated(LinkedList &list)
{
    if (list.head == nullptr)
    {
        return;
    }
    Node *curBlock = list.head;
    while (curBlock != nullptr)
    {
        int cnt = 0;
        Node *moveBlock = curBlock->next;
        while (moveBlock != nullptr)
        {
            cnt++;
            if (moveBlock->data == curBlock->data)
            {
                rmAfterKElements(curBlock, cnt-1);
                moveBlock = curBlock->next;
            }
            else
            {
                moveBlock = moveBlock->next;
            }
        }
        curBlock = curBlock->next;
    }
}
int main()
{
    LinkedList list;
    int input = -1;
    while (true)
    {
        cin >> input;
        if (input == 0)
        {
            break;
        }
        addNewNode(list, input);
    }
    rmDuplicated(list);
    dispList(list);

    return 0;
}