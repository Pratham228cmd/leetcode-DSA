class Solution {
public:
  int helper(int n,int k,vector<vector<int>> &dp){
      if(n==0 || n==1)return n;
      if(k==1)return n;
      if(dp[k][n]!=-1)return dp[k][n];
      int ans=INT_MAX;int l=1,h=n;
      int temp=0;
      while(h>=l){
          int mid=(l+h)/2;
          int left=helper(mid-1,k-1,dp);
          int right=helper(n-mid,k,dp);
          temp=1+max(left,right);
          if(right>left){
              l=mid+1;
          }
          else h=mid-1;
          ans=min(ans,temp);
      }
     return dp[k][n]=ans;
      
  }
    int superEggDrop(int k, int n) {
         vector<vector<int>> dp(k+1,vector<int> (n+1,-1));
        return helper(n,k,dp);
    }
};