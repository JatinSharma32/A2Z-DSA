#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

void traversingLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node *createDummyLinkedList();

Node *InHead(Node *head, int elem)
{
    Node *newNode = new Node(elem);
    newNode->next = head;
    return newNode;
}
Node *InEnd(Node *head, int elem)
{
    Node *newNode = new Node(elem);
    if (head == nullptr)
        return newNode;
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node *InPos(Node *head, int elem, int pos)
{
    Node *newNode = new Node(elem);
    if (head == nullptr)
    {
        if (pos == 1)
            return newNode;
        else
        {
            return nullptr;
        }
    }
    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }
    Node *temp = head->next;
    int counter = 1;
    while (temp != nullptr)
    {
        counter++;
        if (counter == pos - 1)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *head = createDummyLinkedList();
    traversingLL(head);
    head = InPos(head, 99, 1);
    head = InHead(head, 6);
    head = InEnd(head, 45);
    traversingLL(head);
}

Node *createDummyLinkedList()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    return head;
}