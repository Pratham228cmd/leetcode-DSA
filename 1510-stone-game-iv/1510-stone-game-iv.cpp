class Solution {
public:
    // int dp[100005];
    
    bool winnerSquareGame(int n) {
        vector<bool>dp(n+1,0);
        dp[0]=false;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[i-j*j]==false){
                    dp[i]=1;
                    break;
                }
            }
        }
        return dp[n];
        
        
        
    }
};