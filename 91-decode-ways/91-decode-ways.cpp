class Solution {
public:
    int dp[102];
    int helper(string s,int n,int indx){
        if(indx<n and s[indx]=='0')return 0;
        if(indx>=n)return 1;
        if(dp[indx]!=-1)return dp[indx];
        int ans=0;
        if(s[indx]!='0')ans+=helper(s,n,indx+1);
        if(indx+1<n and ((s[indx] == '1' && s[indx+1] <= '9') || (s[indx]=='2' && s[indx+1] < '7'))) ans+=helper(s,n,indx+2);
        return dp[indx]=ans;
        
    }
    int numDecodings(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return helper(s,n,0);
    }
};