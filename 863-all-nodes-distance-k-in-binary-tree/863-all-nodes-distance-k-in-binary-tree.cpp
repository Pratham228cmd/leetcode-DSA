class Solution {
public:
    vector<int> ans;
    int vis[501];
    void dfs(TreeNode* root, vector<vector<int>> &adj)
    {
        if(!root) return;
        if(root->left)
        {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left, adj);
        }
        if(root->right)
        {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right, adj);
        }
    }
    void bfs(int target, int k, vector<vector<int>> &adj)
    {
        queue<int> q;
        q.push(target);
        int layer = 0;
        while(!q.empty())
        {
            if(layer==k) break;
            int size=q.size();
            while(size--)
            {
                int front = q.front();
                q.pop();
                vis[front]=1;
                for(int child: adj[front])
                {
                    if(vis[child]) continue;
                    q.push(child);
                    vis[child] = 1;
                }
            }
            layer++;
        }
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        memset(vis, 0, sizeof(vis));
        vector<vector<int>> adj(501);
        dfs(root, adj);    
        bfs(target->val, k, adj);
        return ans;
    }
};