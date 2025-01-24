#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * Problem Description: https://leetcode.com/problems/linked-list-cycle/description/
 *
 * Brute force: T(n), S(n)
 * Using map find the repeating nodes.
 *
 * Optimized solution: T(n), S(1)
 * Slow and fast pointer will be used at some extent of time they both will
 * be at the same node means there's loop.
 * why? because imagine docking in SFS, if 1 pointer is moving slow (1x speed)
 * and second is moving fast (2x speed) in the same direction ther are
 * supposed to meet.
 *
 */

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};

// Helper function to create a linked list with a cycle
ListNode *createLinkedListWithCycle(vector<int> values, int pos)
{
    if (values.empty())
        return nullptr;
    ListNode *head = new ListNode(values[0]);
    ListNode *tail = head;
    ListNode *cycleNode = nullptr;
    if (pos == 0)
        cycleNode = head;
    for (int i = 1; i < values.size(); ++i)
    {
        tail->next = new ListNode(values[i]);
        tail = tail->next;
        if (i == pos)
            cycleNode = tail;
    }
    if (cycleNode != nullptr)
        tail->next = cycleNode;
    return head;
}

// Helper function to print the linked list (for debugging purposes)
void printList(ListNode *head)
{
    unordered_set<ListNode *> visited;
    while (head != nullptr && visited.find(head) == visited.end())
    {
        cout << head->val << " ";
        visited.insert(head);
        head = head->next;
    }
    if (head != nullptr)
    {
        cout << "(cycle detected)";
    }
    cout << endl;
}

int main()
{
    Solution sol;

    // Example 1: Linked list with a cycle
    vector<int> values1 = {3, 2, 0, -4};
    int pos1 = 1; // The cycle starts at index 1
    ListNode *head1 = createLinkedListWithCycle(values1, pos1);
    cout << "List 1: ";
    printList(head1);
    cout << "Has cycle: " << (sol.hasCycle(head1) ? "Yes" : "No") << endl;

    // Example 2: Linked list without a cycle
    vector<int> values2 = {1, 2};
    int pos2 = -1; // No cycle
    ListNode *head2 = createLinkedListWithCycle(values2, pos2);
    cout << "List 2: ";
    printList(head2);
    cout << "Has cycle: " << (sol.hasCycle(head2) ? "Yes" : "No") << endl;

    return 0;
}