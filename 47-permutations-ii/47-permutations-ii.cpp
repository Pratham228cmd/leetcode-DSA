class Solution {
public:
    int n;
    vector<vector<int>>res;
    set<vector<int>>st;
    void helper(vector<int>& nums,vector<int>&temp,int indx,vector<int>vis){
        if(temp.size()==n){
            // if(st.find(temp)==st.end())
            // res.push_back(temp);
            st.insert(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
            temp.push_back(nums[i]);
            helper(nums,temp,indx+1,vis);
            temp.pop_back();
                vis[i]=0;
        }}
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        vector<int>temp,vis(n,0);
        helper(nums,temp,0,vis);
        for(auto it:st){
            res.push_back(it);
        }
        return res;
    }
};