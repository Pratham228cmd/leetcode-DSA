/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct cmp{
    bool operator()(struct ListNode* p1,struct ListNode* p2){
        return p1->val>p2->val;
    }
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
          if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
    {
        return l2;
    }
    
    if(l2==NULL)
    {
        return l1;
    }
        ListNode *first=l1;
        ListNode *second=l2;
        
        ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;
        while(first and second){
            if(first->val<second->val){
                temp->next=first;
                temp=temp->next;
                first=first->next;
            }
            else{
                temp->next=second;
                temp=temp->next;
                second=second->next;
            }
        }
        if(first!=NULL){
            temp->next=first;
        }
        if(second!=NULL){
            temp->next=second;
        }
        
        return dummy->next;
    }
};