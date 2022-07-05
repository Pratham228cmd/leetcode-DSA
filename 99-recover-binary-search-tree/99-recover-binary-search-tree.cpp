/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
      TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last; 
    void helper(TreeNode *root){
        if(!root) return;
        helper(root->left);
        if(prev and prev->val>root->val){
            if(!first){
                first=prev;
                middle=root;
            }
            else last=root;
        }
        prev=root;
        helper(root->right);
    }
    void recoverTree(TreeNode* root) {
        // if(!root)return root;
         // TreeNode*first=NULL,*mid=NULL,*prev=NULL,*last=NULL;
        first = middle = last = NULL; 
        prev = new TreeNode(INT_MIN); 
        helper(root);
        if(first && last) swap(first->val, last->val); 
        else if(first && middle) swap(first->val, middle->val); 
    }
};