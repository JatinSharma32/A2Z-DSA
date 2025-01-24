#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *rev(ListNode *head)
    {
        if (head->next == nullptr)
        {
            return head;
        }
        ListNode *newHead = rev(head->next);
        ListNode *n = head->next;
        n->next = head;
        return newHead;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *tail = rev(head);
        head->next = nullptr;
        return tail;
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode *reversedHead = sol.reverseList(head);

    std::cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}