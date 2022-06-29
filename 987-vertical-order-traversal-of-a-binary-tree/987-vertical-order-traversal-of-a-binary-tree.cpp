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
    void helper( map<int, vector<pair<int, int>>>&mp,TreeNode*root,int hor,int ver){
        if(root==NULL)return;
        mp[hor].push_back({ver,root->val});
        helper(mp,root->left,hor-1,ver+1);
        helper(mp,root->right,hor+1,ver+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         map<int, vector<pair<int, int>>>mp;
        helper(mp,root,0,0);
        vector<vector<int>>res;
        for(auto entry:mp){
             sort(entry.second.begin(), entry.second.end());
            vector<int> vertical;
            for(auto &_pair : entry.second) {
                vertical.push_back(_pair.second);
            }
            res.push_back(vertical);
        }
        return res;
        
    }
};