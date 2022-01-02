class Solution {
public:
    int dp[31][1001];
    int solve(int n,int k,int target){
        if(target<0)return 0;
        if(n==0 and target==0)return 1;
        if(n==0 || target==0)return 0;
        if(dp[n][target]!=-1)return dp[n][target];
        long long res=0;
        for(int i=1;i<=k;i++){
            
            res+=solve(n-1,k,target-i);
        }
        return dp[n][target]=res%1000000007;
        
        
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(n,k,target);
    }
};