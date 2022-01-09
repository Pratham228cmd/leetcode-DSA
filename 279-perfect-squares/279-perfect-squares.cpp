class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        for(int i=1;i*i<=n;i++)
            dp[i*i]=1;
        
        for(int i=1;i<=n;i++){
            if(dp[i]==0){
                 int ans = INT_MAX;
                for(int j=1;j<=sqrt(i);j++){
                    ans=min(ans,1+dp[i-j*j]);
                }
                 dp[i]=ans;
            }
           
        }
        return dp[n];
        
    }
};