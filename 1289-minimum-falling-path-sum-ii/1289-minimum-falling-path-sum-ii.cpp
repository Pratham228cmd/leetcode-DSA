class Solution {
public:
    int n;
    int dp[201][201];
    int helper(vector<vector<int>>& arr,int r,int c){
        if(r==n)return 0;
        if(dp[r][c]!=-1)return dp[r][c];int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(c!=i)
            ans=min(ans,helper(arr,r+1,i));
        }
        return dp[r][c]=ans+arr[r][c];
         
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        n=arr.size();
        if(n==1)return arr[0][0];
        memset(dp,-1,sizeof(dp));
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,helper(arr,0,i));
        }
        return ans;
    }
};