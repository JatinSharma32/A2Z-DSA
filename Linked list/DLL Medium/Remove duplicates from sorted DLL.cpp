#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
 *
 * Optimized Soultion: T(n), S(1)
 * We will take a pointer at head and we'll keep deleting its duplicate value nodes
 * using another pointer till a different node is found.
 * Then we have to return the head when we reach the end of node.
 */

/* Definition for doubly-linked list node */
struct Node
{
    int data;
    Node *next, *prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        Node *f = head;
        while (f != nullptr && f->next != nullptr)
        {
            Node *d = f->next;
            while (d != nullptr && d->data == f->data)
            {
                Node *temp = d;
                d = d->next;
                delete temp;
            }
            f->next = d;
            if (d != nullptr)
                d->prev = f;
            f = f->next;
        }
        return head;
    }
};

// Helper function to create a doubly linked list from a vector
Node *createDoublyLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    Node *head = new Node(values[0]);
    Node *tail = head;
    for (int i = 1; i < values.size(); ++i)
    {
        tail->next = new Node(values[i]);
        tail->next->prev = tail;
        tail = tail->next;
    }
    return head;
}

// Helper function to print the doubly linked list (for debugging purposes)
void printList(Node *head)
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
    Solution sol;

    // Creating a sorted doubly linked list: 1 <-> 2 <-> 2 <-> 3 <-> 3 <-> 4
    vector<int> values = {1, 2, 2, 3, 3, 4};
    Node *head = createDoublyLinkedList(values);

    cout << "Original list: ";
    printList(head);

    Node *result = sol.removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(result);

    return 0;
}