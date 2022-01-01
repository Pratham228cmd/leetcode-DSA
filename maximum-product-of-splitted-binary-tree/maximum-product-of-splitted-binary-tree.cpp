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
    long long total=0;
    long long res=0;
    long long solve(TreeNode*root){
        if(!root)return 0;
        int sum=root->val+solve(root->left)+solve(root->right);
        res=max(res,(total-sum)*sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        total=solve(root);
        solve(root);
        // return res;
        return res % int(pow(10,9)+7);
    }
};