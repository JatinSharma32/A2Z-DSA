#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};

Node *DelHead(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head->next;
    head->next = nullptr; // Optional
    delete head;
    return temp;
}

Node *DelTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;
    Node *temp = head;
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = nullptr;
    return head;
}

Node *DelPos(Node *head, int pos)
{
    if (pos == 1)
        return DelHead(head);

    int curr = 0;
    Node *temp = head;
    Node *prev = nullptr;
    while (temp != nullptr)
    {
        curr++;
        if (curr == pos)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *DelValue(Node *head, int val)
{
    if (head == nullptr)
        return nullptr;
    // if (head->next == nullptr && head->data == val)
    //     return nullptr;

    Node *temp = head;
    Node *prev = nullptr;
    if (head->data == val)
    {
        head = head->next;
        delete temp;
        return head;
    }

    while (temp != nullptr)
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

void clearList(Node *head)
{
    if (head == nullptr)
        return;
    clearList(head->next);
    cout << "Deleting: " << head->data << "\n";
    delete head;
}

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

int main()
{
    Node *head = createDummyLinkedList();
    traversingLL(head);
    // head = DelHead(head);
    // traversingLL(head);
    // head = DelTail(head);
    // clearList(head);
    // head = DelPos(head, 5);
    head = DelValue(head, 4);
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