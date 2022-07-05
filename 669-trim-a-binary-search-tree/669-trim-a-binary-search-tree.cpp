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
    TreeNode* trimBST(TreeNode* root, int l, int h) {
        if(!root)return NULL;
        root->left=trimBST(root->left,l,h);
        root->right=trimBST(root->right,l,h);
        if(root->val<l)
            return trimBST(root->right,l,h);
        if(root->val>h)
            return trimBST(root->left,l,h);
        
        return root;
        
    }
};