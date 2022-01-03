class Solution {
public:
    int lastStoneWeightII(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        int ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(j==0)dp[i][j]=1;
                else if(i==0 and j!=0)dp[i][j]=0;
                else if(arr[i-1]>j)dp[i][j]=dp[i-1][j];
                else dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    
            }
        }
        for(int i=0;i<=sum;i++){
            if(dp[n][i]){
                int s1=i;
                int s2=sum-i;
                 ans = min(ans,abs(s1-s2));
            }
        }
        return ans;
        
        
        
    }
};