#include <iostream>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/add-two-numbers
 *
 * Optimized Solution: T(n), S(1)
 * We traverse both linked lists till both of them becomes null and while each
 * iteration, we add both the nodes and add them in a dummy linked list and
 * update the carry which is initially zero.
 *
 * finally after that if the carry is still there then we add it at the end as
 * a new node.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *mover1 = l1;
        ListNode *mover2 = l2;
        ListNode *dummyHead = new ListNode(-1);
        ListNode *mover3 = dummyHead;

        int carry = 0;
        while (mover1 != nullptr || mover2 != nullptr)
        {
            int v1 = (mover1 != nullptr) ? mover1->val : 0;
            int v2 = (mover2 != nullptr) ? mover2->val : 0;
            int val = v1 + v2 + carry;
            ListNode *temp = new ListNode(val);
            mover3->next = temp;
            mover3 = temp;
            if (mover3->val >= 10)
            {
                int lastDig = (mover3->val) % 10;
                carry = (mover3->val) / 10;
                (mover3->val) = lastDig;
            }
            else
            {
                carry = 0;
            }
            if (mover1 != nullptr)
                mover1 = mover1->next;
            if (mover2 != nullptr)
                mover2 = mover2->next;
        }

        if (carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            mover3->next = temp;
            mover3 = temp;
        }

        mover3 = dummyHead->next;
        delete dummyHead;
        return mover3;
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

    // Creating two linked lists: 2 -> 4 -> 3 and 5 -> 6 -> 4
    vector<int> values1 = {2, 4, 3};
    vector<int> values2 = {5, 6, 4};
    ListNode *l1 = createLinkedList(values1);
    ListNode *l2 = createLinkedList(values2);

    cout << "List 1: ";
    printList(l1);
    cout << "List 2: ";
    printList(l2);

    ListNode *result = sol.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}