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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode*temp=head->next;
        ListNode*prev=head;
        while(temp){
            if(temp->val!=prev->val){
                prev=temp;
            }
            else{
                prev->next=temp->next;
            }
            temp=temp->next;
        }
        return head;
    }
};