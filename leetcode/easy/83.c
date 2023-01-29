// https://leetcode.com/problems/remove-duplicates-from-sorted-list/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *h = head;
    struct ListNode *t;

    while(h){
        if(h->next && (h->val == h->next->val)){
            t = h->next;
            h->next = h->next->next;
            free(t);
        }
        else h = h->next;
    }
    return head;
}