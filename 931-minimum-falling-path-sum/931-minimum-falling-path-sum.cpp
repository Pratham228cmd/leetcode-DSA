class Solution {
public:
    int n;
    int dp[101][101];
    int helper(int row,int col,vector<vector<int>>& arr){
        // int ans=INT_MAX;
        if(row<0 || col>=n || row>=n || col<0)return INT_MAX;
        if(dp[row][col]!=-1)return dp[row][col];
        int a=helper(row+1,col-1,arr);
        int b=helper(row+1,col,arr);
        int c=helper(row+1,col+1,arr);
        int val=min({a,b,c});
        if(val!=INT_MAX)
        return dp[row][col]=arr[row][col]+min({a,b,c});
        else return dp[row][col]=arr[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& arr) {
        n=arr.size();
        int ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans=min(ans,helper(0,i,arr));
        }
        return ans;
    }
};