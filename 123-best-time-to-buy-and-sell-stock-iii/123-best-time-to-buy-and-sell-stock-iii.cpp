class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,0);
        int maxi=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]>maxi)
                maxi=arr[i];
            dp[i]=max(dp[i+1],maxi-arr[i]);
        }
        maxi=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]<maxi)
                maxi=arr[i];
            
            dp[i]=max(dp[i-1],dp[i]+arr[i]-maxi);
        }
        return dp[n-1];
        
        
        
    }
};