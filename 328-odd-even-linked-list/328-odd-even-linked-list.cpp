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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next ==nullptr)
            return head;
        
        ListNode* odd = head,*o=head;
        ListNode* even=head->next, *e=head->next;
        int i=3;
            head=head->next->next;
        while(head!=NULL){
            if(i%2==0){
                e->next=head;
                e=e->next;
            }
            else {o->next=head; o=o->next;}
            
            i++;
            head=head->next;
        }
        if(even) {o->next=even; e->next=NULL;}
        return odd;
    }
};