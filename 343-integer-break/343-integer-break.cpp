class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n==0 || n==1)return 1;
        if(dp[n]!=-1)return dp[n];
        int max_val=0;
        for(int i=1;i<=n;i++){
            max_val=max(max_val,i*helper(n-i,dp));
        }
        return dp[n]=max_val;
    }
    int integerBreak(int n) {
        if(n<=3)
        {
            return n-1;
        }
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};