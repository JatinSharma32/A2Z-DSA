#include <iostream>
using namespace std;

/**
 * Problem Description: https://leetcode.com/problems/linked-list-cycle-ii/
 *
 * Brute force: T(n), S(n)
 * Using map find the 1st repeating node.
 *
 * Optimized solution: T(n), S(1)
 * Using slow and fast pointer, we found the loop in LL, by getting slow and
 * fast pointer at same node.
 * Now we'll put a pointer at head of LL and keep other at its place
 * Now move both of slow and fast pointers by one node, again the place where
 * they meet will be the head of LL.
 *
 * Proof: https://youtu.be/2Kd0KKmmHFc
 *
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main()
{
    // Creating a linked list with a cycle for testing: 1 -> 2 -> 3 -> 4 -> 5 -> 2 (cycle)
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next; // Creating a cycle

    Solution sol;
    ListNode *cycleStart = sol.detectCycle(head);
    if (cycleStart != nullptr)
    {
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    }
    else
    {
        cout << "No cycle detected." << endl;
    }

    return 0;
}