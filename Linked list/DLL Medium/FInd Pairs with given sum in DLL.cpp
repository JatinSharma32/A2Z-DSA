#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem: https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1
 *
 * Optimized Solution: T(2n), S(1)
 * One pointer at start one at end, so we move both of them accordingly as they make
 * up the sum, and add the pairs that make the sum in a vector, and finally return.
 */

/* Doubly linked list node class */
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        if (head->next == nullptr)
            return {{head->data, head->data}};
        Node *l = head;
        Node *r = head->next;
        while (r->next != nullptr)
            r = r->next;

        vector<pair<int, int>> res;
        while (l != r && l->prev != r)
        {
            int sum = l->data + r->data;
            if (sum == target)
            {
                res.push_back({l->data, r->data});
                l = l->next;
                r = r->prev;
            }
            else if (sum > target)
            {
                r = r->prev;
            }
            else
            {
                l = l->next;
            }
        }
        return res;
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

    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    vector<int> values = {1, 2, 3, 4, 5};
    Node *head = createDoublyLinkedList(values);

    cout << "Original list: ";
    printList(head);

    int target = 5;
    vector<pair<int, int>> result = sol.findPairsWithGivenSum(head, target);

    cout << "Pairs with sum " << target << ": ";
    for (const auto &p : result)
    {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;

    return 0;
}