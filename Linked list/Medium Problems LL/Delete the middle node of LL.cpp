#include <iostream>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list
 *
 * Optimied Solution: T(n), S(1)
 * Using slow and fast pointer, find the middle point keep track of its
 * previous, and simply delete it.
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
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == nullptr)
            return nullptr;
        if (head->next->next == nullptr)
        {
            auto d = head->next;
            head->next = nullptr;
            delete d;
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = nullptr;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = slow->next;
        delete slow;
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
    ListNode *result = sol.deleteMiddle(head);

    cout << "List after deleting the middle node: ";
    printList(result);

    return 0;
}