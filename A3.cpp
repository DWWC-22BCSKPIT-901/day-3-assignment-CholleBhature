#include <iostream>
#include <vector> 
using namespace std;

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
        ListNode *dummyHead = new ListNode(0);
        ListNode *current = dummyHead;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0)
        {
            int sum = carry;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        return dummyHead->next;
    }
};

ListNode *createLinkedList(const vector<int> &nums)
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;

    for (int num : nums)
    {
        ListNode *newNode = new ListNode(num);
        if (!head)
        {
            head = newNode;
            tail = head;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}

void printLinkedList(ListNode *head)
{
    while (head)
    {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Solution solution;

    ListNode *l1 = createLinkedList({2, 4, 3});
    ListNode *l2 = createLinkedList({5, 6, 4});
    ListNode *result = solution.addTwoNumbers(l1, l2);

    printLinkedList(result); 

    l1 = createLinkedList({0});
    l2 = createLinkedList({0});
    result = solution.addTwoNumbers(l1, l2);

    printLinkedList(result); 

    l1 = createLinkedList({9, 9, 9, 9, 9, 9, 9});
    l2 = createLinkedList({9, 9, 9, 9});
    result = solution.addTwoNumbers(l1, l2);

    printLinkedList(result);

    return 0;
}
