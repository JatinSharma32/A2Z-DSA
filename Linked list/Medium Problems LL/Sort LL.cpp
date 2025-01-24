#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/sort-list
 *
 * Optimized: T(n*logn), S(1)
 * We use merge sort here where, we keep dividing the list in halfs (point middle
 * node to null pointer) till single element, then while merging them make a dummy
 * node and add both lists elements after comparing then add the smaller node's
 * elements to it and return it.
 *
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
    ListNode *merge(ListNode *left, ListNode *right)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *mover = dummyHead;

        while (left != nullptr && right != nullptr)
        {
            if (left->val > right->val)
            {
                mover->next = right;
                mover = right;
                right = right->next;
            }
            else
            {
                mover->next = left;
                mover = left;
                left = left->next;
            }
        }
        if (left)
            mover->next = left;
        else
            mover->next = right;
        mover = dummyHead->next;
        delete dummyHead;
        return mover;
    }

    ListNode *findMiddle(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (fast == nullptr)
        {
            return prev;
        }
        return slow;
    }

    ListNode *mergeSort(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode *middle = findMiddle(head);
        auto rightHead = middle->next;
        middle->next = nullptr;
        auto left = mergeSort(head);
        auto right = mergeSort(rightHead);
        return merge(left, right);
    }

    ListNode *sortList(ListNode *head)
    {
        return mergeSort(head);
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

    // Example: Sort the linked list
    vector<int> values = {4, 2, 1, 3};
    ListNode *head = createLinkedList(values);
    cout << "Original list: ";
    printList(head);
    ListNode *sortedHead = sol.sortList(head);
    cout << "Sorted list: ";
    printList(sortedHead);

    return 0;
}