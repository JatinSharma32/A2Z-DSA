#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/intersection-of-two-linked-lists/
 *
 * Optimized: T(2n), S(1)
 * So here the intersection point will be found by traversing both linked lists
 * till end and after that we move it to the opposit head (tempA to headB) and
 * (tempB to headA) so by doing this we bring them at the nodes which have same
 * distance from the intersection point from there keep checking if they are at
 * the same node.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *tempA = headA;
        ListNode *tempB = headB;
        if (tempA == tempB)
            return tempA;
        while (tempA != tempB)
        {
            tempA = tempA->next;
            tempB = tempB->next;
            if (tempA == tempB)
            {
                return tempA;
            }
            if (tempA == nullptr)
                tempA = headB;
            if (tempB == nullptr)
                tempB = headA;
        }
        return tempA;
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

    // Creating two linked lists with an intersection
    // List A: 1 -> 2 -> 3
    // List B: 4 -> 5
    // Intersection: 6 -> 7
    ListNode *intersect = createLinkedList({6, 7});
    ListNode *headA = createLinkedList({1, 2, 3});
    ListNode *headB = createLinkedList({4, 5});
    ListNode *tempA = headA;
    while (tempA->next != nullptr)
        tempA = tempA->next;
    tempA->next = intersect;
    ListNode *tempB = headB;
    while (tempB->next != nullptr)
        tempB = tempB->next;
    tempB->next = intersect;

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    ListNode *intersection = sol.getIntersectionNode(headA, headB);
    if (intersection)
    {
        cout << "Intersection at node with value: " << intersection->val << endl;
    }
    else
    {
        cout << "No intersection." << endl;
    }

    return 0;
}