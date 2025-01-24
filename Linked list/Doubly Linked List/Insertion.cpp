#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node(int n)
    {
        data = n;
        prev = nullptr;
        next = nullptr;
    }
};

void traversingDLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node *createDummyDLL()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    return head;
}

Node *InEnd(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
        return newNode;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node *InPos(Node *head, int pos, int data)
{
    Node *newNode = new Node(data);
    int curr = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        curr++;
        if (curr == pos)
            break;
        temp = temp->next;
    }
    Node *nx = temp->next;
    if (nx != nullptr)
        nx->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nx;

    return head;
}

int main()
{
    Node *head = createDummyDLL();
    traversingDLL(head);
    head = InEnd(head, 56);
    traversingDLL(head);
    head = InPos(head, 6, 78);
    traversingDLL(head);
    return 0;
}