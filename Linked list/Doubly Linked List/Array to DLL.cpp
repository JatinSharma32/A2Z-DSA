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

Node *ArrToDLL(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *mover = head;
    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
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

int main()
{
    vector<int> v = {43, 5, 3, 25, 4, 2};
    Node *head = ArrToDLL(v);
    traversingDLL(head);
    return 0;
}