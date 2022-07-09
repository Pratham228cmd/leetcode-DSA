/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *heada, ListNode *headb) {
        ListNode*a=heada,*b=headb;
        while(a!=b){
            a=a?a->next:headb;
            b=b?b->next:heada;
        }
        return b;
    }
};