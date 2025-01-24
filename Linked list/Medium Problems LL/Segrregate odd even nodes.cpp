#include <iostream>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/odd-even-linked-list
 *
 * Optimized solution: T(2n) S(1)
 * Keep pointers at head & tail, then take the even node delete it and
 * add it at the end
 * Stop when the original tail is reached.
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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return head;

        ListNode *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        ListNode *originalLast = last;

        ListNode *p = head;
        while (p != originalLast && p->next != originalLast)
        {
            ListNode *c = p->next;
            p->next = c->next;
            c->next = nullptr;
            last->next = c;
            last = c;
            p = p->next;
        }
        if (p->next == originalLast)
        {
            ListNode *c = p->next;
            p->next = c->next;
            c->next = nullptr;
            last->next = c;
            last = c;
        }

        return head;
    }
};

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
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode *result = sol.oddEvenList(head);

    cout << "Segregated list: ";
    printList(result);

    return 0;
}