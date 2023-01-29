
// Definition for singly-linked list.
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int count = 0;

        int total = 0;
        while (temp)
        {
            temp = temp->next;
            total++;
        }

        temp = head;

        if (total == n)
        {
            return head->next;
        }

        while (temp)
        {
            if ((total - count) == n + 1)
            {
                temp->next = (temp->next == nullptr) ? nullptr : temp->next->next;
            }
            count++;
            temp = temp->next;
        }
        return head;
    }
};
