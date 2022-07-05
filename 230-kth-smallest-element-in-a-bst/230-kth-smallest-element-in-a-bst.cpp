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
    vector<int>vec;
    int ans;
    void inorder(TreeNode*root,int &c,int k){
        if(root==NULL) return;
        inorder(root->left,c,k);
        c++;
        if(c==k)
        { ans=root->val;return;}
        // vec.push_back(root->val);
        
        inorder(root->right,c,k);
       
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        inorder(root,c,k);
        return ans;
    }
};