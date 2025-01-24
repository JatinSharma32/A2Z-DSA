#include <iostream>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 *
 * Optimized solution: T(2n), S(1)
 * Find the length of the LL, and the in refernece to it find the deleting
 * index from the start, if its the head then delete head, otherwise delete the required node by traversing it and delete it
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == nullptr)
            return nullptr;
        ListNode *tail = head;
        int counter = 0;
        while (tail != nullptr)
        {
            counter++;
            tail = tail->next;
        }
        int deleteIndex = counter - n;

        if (deleteIndex == 0)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }
        counter = 0;
        tail = head;
        while (tail != nullptr)
        {
            counter++;
            if (counter == deleteIndex)
            {
                ListNode *d = tail->next;
                tail->next = tail->next->next;
                delete d;
                return head;
            }
            tail = tail->next;
        }
        return head;
    }
};

// Helper function to create a linked list from a vector
ListNode *createLinkedList(const vector<int> &values)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *tail = head;
    for (int i = 1; i < values.size(); ++i)
    {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
    }
    return head;
}

// Helper function to print the linked list (for debugging purposes)
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Example 1: Remove the 2nd node from the end
    vector<int> values1 = {1, 2, 3, 4, 5};
    ListNode *head1 = createLinkedList(values1);
    cout << "Original list: ";
    printList(head1);
    ListNode *result1 = sol.removeNthFromEnd(head1, 2);
    cout << "List after removing 2nd node from the end: ";
    printList(result1);

    // Example 2: Remove the 1st node from the end
    vector<int> values2 = {1};
    ListNode *head2 = createLinkedList(values2);
    cout << "Original list: ";
    printList(head2);
    ListNode *result2 = sol.removeNthFromEnd(head2, 1);
    cout << "List after removing 1st node from the end: ";
    printList(result2);

    return 0;
}