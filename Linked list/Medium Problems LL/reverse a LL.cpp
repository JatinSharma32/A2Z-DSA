#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d) : data(d), next(nullptr) {};
};

void display(Node *head)
{
    // Printing the linked list
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *rev(Node *head)
{
    if (head == nullptr)
        return nullptr;
    Node *p = nullptr;
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *n = temp->next;
        temp->next = p;
        p = temp;
        temp = n;
    }
    return p;
}

int main()
{
    // Creating a dummy linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    display(head);
    display(rev(head));
    return 0;
}
