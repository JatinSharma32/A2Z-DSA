#include <bits/stdc++.h>
using namespace std;
/**
 * Problem: https://leetcode.com/problems/rotate-list/
 *
 * Optimized Solution: T(2n), S(1)
 * Find the length of the LL and then find the (K % Len) to optimize the Operations
 * then find that (K % Len) element and romve it from the end and point the tail
 * on the head, return new head.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        int length = 1;
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
            length++;
        }

        int rotations = k % length;
        if (rotations == 0)
            return head;
        int reach = length - rotations;

        ListNode *temp = head;
        ListNode *newHead = head;
        int checker = 0;
        while (temp != nullptr)
        {
            checker++;
            if (reach == checker)
                break;
            temp = temp->next;
        }

        newHead = temp->next;
        tail->next = head;
        temp->next = nullptr;
        return newHead;
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

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(values);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    ListNode *result = sol.rotateRight(head, k);

    cout << "List after rotating right by " << k << " positions: ";
    printList(result);

    return 0;
}