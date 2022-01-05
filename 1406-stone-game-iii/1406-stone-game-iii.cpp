class Solution {
public:
    int util(vector<int>&arr,int dp[],int i,int n)
    {
        if(dp[i]!=-1)
        return dp[i];
        if(i>=n)
        return (dp[i]=0);
        int res=INT_MIN;
        res=max(res,arr[i]+min(util(arr,dp,i+4,n),min(util(arr,dp,i+2,n),util(arr,dp,i+3,n))));
        if(i+1<n)
        res=max(res,arr[i]+arr[i+1]+min(util(arr,dp,i+3,n),min(util(arr,dp,i+4,n),util(arr,dp,i+5,n))));
        if(i+2<n)
        res=max(res,arr[i]+arr[i+1]+arr[i+2]+min(util(arr,dp,i+4,n),min(util(arr,dp,i+5,n),util(arr,dp,i+6,n))));
        return dp[i]=res;
    }
    string stoneGameIII(vector<int>& arr) {
        int n=arr.size();
        int dp[n+5];
        memset(dp,-1,sizeof(dp));
        int alice=util(arr,dp,0,n);
        int sum=0;
        for(int i=0;i<n;i++)
        sum=sum+arr[i];
        int bob=sum-alice;
        if(bob>alice)
        return "Bob";
        else if(bob==alice)
        return "Tie";
        else
        return "Alice";
    }
};
