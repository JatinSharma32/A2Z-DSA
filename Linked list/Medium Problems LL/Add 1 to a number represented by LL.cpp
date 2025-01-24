#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1
 *
 * Optimized: T(n), S(1)
 * We are given a number 123 as (1)->(2)->(3)->null
 * So if we want to add 1 to this we have to do this operation in reverse order so using
 * recursion we add 1 to the number and return the carry to previous node in recursion
 * and so on...
 * Finally in the end if carry is left then add it before the head node.
 *
 */

/**
 * Definition for singly-linked list.
 */
struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    int trv(Node *head)
    {
        if (head == nullptr)
            return 1;
        int carry = trv(head->next);
        head->data = head->data + carry;
        if (head->data < 10)
        {
            return 0;
        }
        else
        {
            head->data = 0;
            return 1;
        }
    }

    Node *addOne(Node *head)
    {
        int carry = trv(head);
        if (carry == 1)
        {
            Node *h = new Node(1);
            h->next = head;
            return h;
        }
        return head;
    }
};

// Helper function to create a linked list from a vector
Node *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    Node *head = new Node(values[0]);
    Node *tail = head;
    for (int i = 1; i < values.size(); ++i)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
    }
    return head;
}

// Helper function to print the linked list (for debugging purposes)
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
    // Creating a linked list: 1 -> 2 -> 9
    vector<int> values = {1, 2, 9};
    Node *head = createLinkedList(values);

    Solution sol;
    Node *result = sol.addOne(head);

    cout << "List after adding one: ";
    printList(result);

    return 0;
}