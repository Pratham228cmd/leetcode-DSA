class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int>dp(n+1,INT_MAX),indx(primes.size(),0);
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<primes.size();j++){
                dp[i]=min(dp[i],primes[j]*dp[indx[j]]);
            }
             for(int j=0;j<primes.size();j++){
                 indx[j]+=(dp[i]==primes[j]*dp[indx[j]]);
             }
            
        }
        return dp[n-1];
    }
};