#include <iostream>
#include <vector>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/palindrome-linked-list/
 *
 * Optimized solution: T(3n), S(1)
 * We'll do it in 3 steps
 * 1. We have to reverse the second half of the linked list, for that find
 *    the break point of LL and reverse it.
 * 2. Now 1 pointer at head one at breakpoint, run both of them and compare
 *    For plaindrome, store the boolean result
 * 3. Again rever the second half to bring it in original state, return result
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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *reverseMergePoint = nullptr;

        // Checking the Odd or even and finding the break point
        while (fast != nullptr && fast->next != nullptr)
        {
            reverseMergePoint = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *revHead;
        if (fast == nullptr)
        {
            // even
            revHead = slow;
        }
        else
        {
            // odd
            revHead = slow->next;
            reverseMergePoint = slow;
        }

        // Reversing the other half
        ListNode *p = nullptr;
        while (revHead != nullptr)
        {
            ListNode *n = revHead->next;
            revHead->next = p;
            p = revHead;
            revHead = n;
        }
        reverseMergePoint->next = p;

        // Compare the List
        ListNode *i = head;
        ListNode *j = reverseMergePoint->next;
        bool res = true;
        while (j != nullptr)
        {
            if (i->val != j->val)
            {
                res = false;
                break;
            }
            i = i->next;
            j = j->next;
        }

        // Again Reversing the other half
        p = nullptr;
        revHead = reverseMergePoint->next;
        while (revHead != nullptr)
        {
            ListNode *n = revHead->next;
            revHead->next = p;
            p = revHead;
            revHead = n;
        }
        reverseMergePoint->next = p;
        return res;
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

    // Example 1: Palindrome linked list
    vector<int> values1 = {1, 2, 2, 1};
    ListNode *head1 = createLinkedList(values1);
    cout << "List 1: ";
    printList(head1);
    cout << "Is palindrome: " << (sol.isPalindrome(head1) ? "Yes" : "No") << endl;

    // Example 2: Non-palindrome linked list
    vector<int> values2 = {1, 2, 3, 4};
    ListNode *head2 = createLinkedList(values2);
    cout << "List 2: ";
    printList(head2);
    cout << "Is palindrome: " << (sol.isPalindrome(head2) ? "Yes" : "No") << endl;

    return 0;
}