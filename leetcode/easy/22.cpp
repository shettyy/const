//https://leetcode.com/problems/merge-two-sorted-lists/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3orig = nullptr;
        ListNode* l3 = new ListNode();
        while((l1!=nullptr) || (l2!=nullptr))
        {
            //cout<<"l1"<<l1<<" l2"<<l2<<endl;
            if (((l1!=nullptr) || (l2==nullptr)) && ((l2==nullptr) || (l1->val <= l2->val)))
            {
                //cout<<"l1.val "<<l1->val<<endl;
                l3->next = l1;
                l1 = l1->next;
            }
            else if (l2 != nullptr)
            {
                //cout<<"l2.val "<<l2->val<<endl;
                l3->next = l2;
                l2 = l2->next;
            }
            if(l3orig == nullptr)
            {
                l3orig = l3->next;
            }
            
            l3 = l3->next;
        }
        
        return l3orig;
    }
};