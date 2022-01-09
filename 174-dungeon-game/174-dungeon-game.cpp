class Solution {
public:
    int dp[201][201];
    int m,n;
    int util(int r,int c,vector<vector<int>>&arr){
        if(r==m-1 and c==n-1)return arr[r][c]<=0?1+abs(arr[r][c]):1;
        else if(r>=m || c>=n || r<0 || c<0)return INT_MAX;
        if(dp[r][c]!=-1)return dp[r][c];
        int sum=0;
        int a=util(r+1,c,arr);
        int b=util(r,c+1,arr);
        if(arr[r][c]>=min(a,b))
            return dp[r][c]=1;
        
        else return dp[r][c]=min(a,b)-arr[r][c];
        
        
        
        
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
         m=arr.size();
         n=arr[0].size();
        memset(dp,-1,sizeof(dp));
        return util(0,0,arr);
        
    }
};