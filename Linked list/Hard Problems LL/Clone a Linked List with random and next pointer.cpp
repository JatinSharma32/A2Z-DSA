#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: https://leetcode.com/problems/copy-list-with-random-pointer
 *
 * Optimized Solution: T(3n), S(1)
 * So it can be easily solved using map<original_node, duplicate_node> but the
 * problem is extra space, so to reduce it we stre the duplicate nodes next to their
 * original node
 * Then we seperatly do the relocation of random pointers
 * and finally the relocation of next pointers and make a seperate list return it.
 */

/**
 * Definition for a Node.
 */
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
            return head;
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *preserve = temp->next;
            Node *tempDup = new Node(temp->val);
            temp->next = tempDup;
            tempDup->next = preserve;
            temp = preserve;
        }

        // Below is random pointer relocation
        temp = head;
        while (temp != nullptr)
        {
            Node *originalRandom = temp->random;
            Node *dupNode = temp->next;
            if (originalRandom == nullptr)
                dupNode->random = nullptr;
            else
                dupNode->random = originalRandom->next;
            temp = dupNode->next;
        }

        // Below is next pointer relocation
        Node *dupHead = new Node(-1);
        Node *dupMover = dupHead;
        temp = head;
        while (temp != nullptr)
        {
            dupMover->next = temp->next;
            dupMover = dupMover->next;
            temp->next = temp->next->next;
            dupMover->next = nullptr;
            temp = temp->next;
        }
        temp = dupHead;
        dupHead = dupHead->next;
        delete temp;
        return dupHead;
    }
};

// Helper function to create a linked list with random pointers
Node *createLinkedListWithRandom(const vector<int> &values, const vector<int> &randomIndices)
{
    if (values.empty())
        return nullptr;
    unordered_map<int, Node *> nodeMap;
    Node *head = new Node(values[0]);
    nodeMap[0] = head;
    Node *tail = head;
    for (int i = 1; i < values.size(); ++i)
    {
        tail->next = new Node(values[i]);
        tail = tail->next;
        nodeMap[i] = tail;
    }
    Node *temp = head;
    for (int i = 0; i < randomIndices.size(); ++i)
    {
        if (randomIndices[i] != -1)
        {
            temp->random = nodeMap[randomIndices[i]];
        }
        temp = temp->next;
    }
    return head;
}

// Helper function to print the linked list (for debugging purposes)
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << "Value: " << head->val;
        if (head->random != nullptr)
        {
            cout << ", Random: " << head->random->val;
        }
        else
        {
            cout << ", Random: nullptr";
        }
        cout << endl;
        head = head->next;
    }
}

int main()
{
    Solution sol;

    // Creating a linked list with random pointers
    vector<int> values = {1, 2, 3, 4, 5};
    vector<int> randomIndices = {2, 1, 4, 0, -1}; // -1 indicates nullptr
    Node *head = createLinkedListWithRandom(values, randomIndices);

    cout << "Original list:" << endl;
    printList(head);

    Node *clonedHead = sol.copyRandomList(head);

    cout << "Cloned list:" << endl;
    printList(clonedHead);

    return 0;
}