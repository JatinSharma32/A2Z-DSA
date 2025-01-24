#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/reverse-nodes-in-k-group/
 *
 * Optimized Solution: T(2n) S(1)
 * This problem can be solved in 3 major steps...
 -> 1st we have to find the K'th node from current node and preserve its previous and
    point its end to null.
 -> Then we have to reverse the list and add it back in the original linked list using
    preserved previous.
 -> Finally stop when null comes.
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
    ListNode *rev(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode *newHead = rev(head->next);
        ListNode *n = head->next;
        n->next = head;
        head->next = nullptr; // Fix to avoid cycle
        return newHead;
    }

    ListNode *findKthNode(ListNode *head, int k)
    {
        ListNode *mover = head;
        int counter = 0;
        while (mover != nullptr)
        {
            counter++;
            if (counter == k)
            {
                break;
            }
            mover = mover->next;
        }
        return mover;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
            return head;
        ListNode *temp = head;
        ListNode *prevPreserve = nullptr;
        while (temp != nullptr)
        {
            ListNode *mover = findKthNode(temp, k);
            if (mover == nullptr)
                break;

            ListNode *preserve = mover->next;
            mover->next = nullptr;

            ListNode *newHead = rev(temp);
            if (temp == head)
                head = newHead;
            else
                prevPreserve->next = newHead;

            temp->next = preserve;
            prevPreserve = temp;
            temp = preserve;
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

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(values);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    ListNode *result = sol.reverseKGroup(head, k);

    cout << "List after reversing every " << k << " nodes: ";
    printList(result);

    return 0;
}