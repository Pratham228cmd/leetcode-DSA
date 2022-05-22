class Solution {
public:
//     int dp[102];
//     int helper(string s,int n,int indx){
//         if(indx<n and s[indx]=='0')return 0;
//         if(indx>=n)return 1;
//         if(dp[indx]!=-1)return dp[indx];
//         int ans=0;
//         if(s[indx]!='0')ans+=helper(s,n,indx+1);
//         if(indx+1<n and ((s[indx] == '1' && s[indx+1] <= '9') || (s[indx]=='2' && s[indx+1] < '7'))) ans+=helper(s,n,indx+2);
//         return dp[indx]=ans;
        
//     }
    int numDecodings(string s) {
         int n=s.size();
        vector<int>dp(n+1,0);
        if(s[0]=='0')return 0;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            if(s[i-1]!='0')
            dp[i]=dp[i-1];
            if(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<'7'))
                dp[i]+=dp[i-2];
            
        }
        return dp[n];
    }
};