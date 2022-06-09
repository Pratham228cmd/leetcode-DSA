class Solution {
public:
    int dp[22][22];
    int helper(int i,int j,vector<int>&nums){
        if(i==j)return nums[i];
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans1=nums[i]+min(helper(i+2,j,nums),helper(i+1,j-1,nums));
        int ans2=nums[j]+min(helper(i+1,j-1,nums),helper(i,j-2,nums));
        return dp[i][j]=max(ans1,ans2);
        
        
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int x=helper(0,nums.size()-1,nums);
          int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        return x>=sum-x;
    }
};