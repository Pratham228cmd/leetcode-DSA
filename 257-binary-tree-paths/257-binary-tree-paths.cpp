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
    vector<string>res;
    void helper(TreeNode* root,string path){
        if(root == NULL)return;
        if(!root->left and !root->right){
            path+=to_string(root->val);
            res.push_back(path);
            return;
        }
        path+=to_string(root->val);;
        path+= "->";
        helper(root->left,path);
        helper(root->right,path);
        
        
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ds;
		// vector<string> ans;
		helper(root,ds);
		return res;
    }
};