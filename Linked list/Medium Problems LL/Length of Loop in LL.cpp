#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/**
 * Problem: https://www.geeksforgeeks.org/problems/find-length-of-loop/1
 *
 * Optimized: T(n), S(1)
 * We can bring slow and fast pointer at same node
 * then we move one of them with a counter till it completes the loop and
 * reaches the starting point.
 */

/**
 * Definition for singly-linked list.
 */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        if (head == nullptr)
            return 0;
        Node *slow = head;
        Node *fast = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                int counter = 1;
                fast = fast->next;
                while (slow != fast)
                {
                    fast = fast->next;
                    counter++;
                }
                return counter;
            }
        }
        return 0;
    }
};

// Helper function to create a linked list with a cycle
Node *createLinkedListWithCycle(vector<int> values, int pos)
{
    if (values.empty())
        return nullptr;
    Node *head = new Node(values[0]);
    Node *tail = head;
    Node *cycleNode = nullptr;
    if (pos == 0)
        cycleNode = head;
    for (int i = 1; i < values.size(); ++i)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
        if (i == pos)
            cycleNode = tail;
    }
    if (cycleNode != nullptr)
        tail->next = cycleNode;
    return head;
}

// Helper function to print the linked list (for debugging purposes)
void printList(Node *head)
{
    unordered_set<Node *> visited;
    while (head != nullptr && visited.find(head) == visited.end())
    {
        cout << head->data << " ";
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
    Node *head1 = createLinkedListWithCycle(values1, pos1);
    cout << "List 1: ";
    printList(head1);
    cout << "Length of cycle: " << sol.countNodesinLoop(head1) << endl;

    // Example 2: Linked list without a cycle
    vector<int> values2 = {1, 2};
    int pos2 = -1; // No cycle
    Node *head2 = createLinkedListWithCycle(values2, pos2);
    cout << "List 2: ";
    printList(head2);
    cout << "Length of cycle: " << sol.countNodesinLoop(head2) << endl;

    return 0;
}