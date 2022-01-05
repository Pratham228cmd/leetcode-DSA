class Solution {
public:
    int a=0,b=0;
    int dp[501][501];
    int helper(vector<int>&arr,int i,int j){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=arr[i]+min(helper(arr,i+2,j),helper(arr,i+1,j-1));
        int b=arr[j]+min(helper(arr,i+1,j-1),helper(arr,i,j-2));
        return dp[i][j]=max(a,b);
    }
    bool stoneGame(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(auto x:arr)sum+=x;
        int x=helper(arr,0,n-1);
        int y=sum-x;
        if(x>y)return true;
        return false;
        
        
    }
};