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
    vector<vector<int>> ans ;
void helper(TreeNode* &root , int tar , int cursum , vector<int>temp){
        if(root==NULL)return;
        if(!root->left and !root->right){
            temp.push_back(root->val);
            cursum+=root->val;
            if(cursum==tar){
                 ans.push_back(temp) ;
            }
            return;
        }
    temp.push_back(root->val);
      helper(root->left , tar , cursum+root->val , temp) ;
    
    temp.pop_back() ; 

    temp.push_back(root->val) ; 
    helper(root->right , tar , cursum+root->val , temp) ;
    
    
    
    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {} ;
vector<int>temp ;
helper(root , targetSum ,0, temp) ;
return ans;
    }
};