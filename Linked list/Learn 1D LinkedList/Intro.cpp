#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int val) : data(val), next(nullptr) {}
};
class Solution
{
public:
    Node *constructLLFromArray(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *mover = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i]);
            mover->next = temp;
            mover = temp;
        }
        return head;
    }
    void traversingLL(Node *head)
    {
        int len = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            len++;
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\nLength is: " << len << "\n";
    }
    Node *searchInLL(Node *head, int elem)
    {
        // Search element in linked list and return pointer to it
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->data == elem)
                break;
            temp = temp->next;
        }
        return temp;
    }
};

int main()
{
    vector<int> arr = {1, 2, 3, 69, 5};
    Solution sol;
    Node *head = sol.constructLLFromArray(arr);
    sol.traversingLL(head);
    cout << "Enter a number to search: ";
    int elem;
    cin >> elem;
    Node *p = sol.searchInLL(head, elem);
    if (p != nullptr)
        cout << "Element found!";
    else
        cout << "Element not found!";
    return 0;
}