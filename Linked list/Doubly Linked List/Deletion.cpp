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

Node *DelHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head->next;
    head->next = nullptr;
    temp->prev = nullptr;
    delete head;
    return temp;
}

Node *DelEnd(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}

Node *DelPos(Node *head, int pos)
{
    if (head == nullptr)
        return nullptr;
    if (pos == 1)
        return DelHead(head);

    Node *temp = head->next;
    int curr = 1;

    while (temp != nullptr)
    {
        curr++;
        if (curr == pos)
            break;
        temp = temp->next;
    }
    if (temp == nullptr && curr < pos) // This is edge case when pos goes out of limit.
        return head;
    if (temp->next == nullptr)
    {
        temp->prev->next = nullptr;
        delete temp;
    }
    else
    {
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;
        delete temp;
    }
    return head;
}

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

int main()
{
    Node *head = createDummyDLL();
    traversingDLL(head);
    head = DelPos(head, 1);
    traversingDLL(head);
    return 0;
}