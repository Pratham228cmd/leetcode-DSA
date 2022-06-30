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
    // int res=INT_MAX;
     void inorder(TreeNode* root,vector<int> &ans)
    {
        if(root == NULL)
            return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    int minDiffInBST(TreeNode* root) {
         if(root == NULL)
            return 0;
        vector<int> ans;
        inorder(root,ans);
        
        int mi = INT_MAX;
        for(int i=0;i<ans.size()-1;i++)
        {
            mi = min(mi,ans[i+1] - ans[i]);
        }
        return mi;
        
    }
};