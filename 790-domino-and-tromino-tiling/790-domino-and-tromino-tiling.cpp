class Solution {
public:
    #define MOD 1000000007
    int helper(int n,vector<int>&dp,int i){
        if(i==n)return 1;
        if(i>n)return 0;
        if(dp[i]!=-1)return dp[i];
        long long ans=0;
        (ans+=(helper(n,dp,i+1)))%=MOD;
        (ans+=(helper(n,dp,i+2)))%=MOD;
        for(int j=3;;j++){
            if(i+j>n){
                break;
            }
            (ans+=(2*helper(n,dp,i+j)))%=MOD;
        }
       return dp[i]=ans;
        
        
    }
    int numTilings(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp,0);
        
    }
};