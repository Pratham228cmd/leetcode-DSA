class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        // vector<vector<int>>dp(m,vector<int>(n,0));
        if(arr[0][0]==1)return 0;
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        // cout<<"pratham1"<<endl;
        for(int i=1;i<m;i++){
            if(arr[i][0]==1)
                dp[i][0]=0;
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<n;i++){
            if(arr[0][i]==1)
                dp[0][i]=0;
            else dp[0][i]=dp[0][i-1];
        }
        // cout<<"pratham1"<<endl;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(arr[i][j]!=1){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        // cout<<"pratham1"<<endl;
        return dp[m-1][n-1];
    }
};