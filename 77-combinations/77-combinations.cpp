class Solution {
public:
    vector<vector<int>> res;
    void helper(int &n,int &k,int i,vector<int>&ans){
        // if(i>n)return;
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        if(i<=n)
        for(int j=i;j<=n;j++){
            ans.push_back(j);
            helper(n,k,j+1,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>ans;
        helper(n,k,1,ans);
        return res;
    }
};