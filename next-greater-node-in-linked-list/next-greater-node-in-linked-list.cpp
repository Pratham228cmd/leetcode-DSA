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
   ListNode* reverse(ListNode*head){
        ListNode*curr=head,*prev=NULL,*temp;
        while(curr){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        // if(!head || !head->next)return head;
        if(!head)return {};
        if(!head->next)return {0};
        head=reverse(head);
        ListNode*temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
        vector<int>ans;
        stack<int>st;
        for(ListNode*temp=head;temp;temp=temp->next){
            if(st.size()==0){
                ans.push_back(0);
                st.push(temp->val);
            }
            else{
                while(st.empty()==false and temp->val>=st.top())
                    st.pop();
                if(st.size()==0){
                    ans.push_back(0);
                st.push(temp->val);
                }
                else{
                    ans.push_back(st.top());
                    st.push(temp->val);
                }
            }
        }
        
        ::reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};