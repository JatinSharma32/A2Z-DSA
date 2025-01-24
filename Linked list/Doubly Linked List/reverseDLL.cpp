#include <iostream>
using namespace std;

// Definition for doubly-linked list node
struct DLLNode
{
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution
{
public:
    // Function to reverse a doubly linked list
    DLLNode *reverseDLL(DLLNode *head)
    {
        if (!head)
            return nullptr;
        DLLNode *temp = head;
        while (temp->next != nullptr)
        {
            DLLNode *n = temp->next;
            temp->next = temp->prev;
            temp->prev = n;
            temp = n;
        }
        // Swap the last node's next and prev pointers
        DLLNode *n = temp->next;
        temp->next = temp->prev;
        temp->prev = n;
        return temp;
    }
};

// Helper function to print the doubly linked list
void printList(DLLNode *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    DLLNode *head = new DLLNode(1);
    head->next = new DLLNode(2);
    head->next->prev = head;
    head->next->next = new DLLNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new DLLNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DLLNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    Solution sol;
    DLLNode *reversedHead = sol.reverseDLL(head);

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}