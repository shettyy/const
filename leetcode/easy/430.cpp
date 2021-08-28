// https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* traverse(Node* head, vector<int> &res) {
        Node* node = head;
        while(node){
            //cout << node->val << " ";
            res.push_back(node->val);
            if(node->child){
                traverse(node->child, res);
            }
            node = node->next;
        }
        return NULL;
    }
    
    Node* createList(vector<int>res){
        Node* head = NULL;
        Node* tail = NULL;
        
        for(auto i:res){
            //cout << i << " ";
            
            Node* node = new Node();
            node->next = NULL;
            node->prev = tail;
            node->child = NULL;
            node->val = i;
            if(head==NULL){
                head = node;
            }
            
            if(tail){
                tail->next = node;
            }
            tail = node;
            
            
        }
        return head;
    }
    
    Node* flatten(Node* head) {
        vector<int> res;
        traverse(head, res);

        Node* node = createList(res);

        /*
        while(node){
            cout << node->val << " ";
            node = node->next;
        }*/
        return node;
    }
};