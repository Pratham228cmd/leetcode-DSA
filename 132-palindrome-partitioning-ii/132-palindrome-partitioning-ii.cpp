class Solution {
public:
    bool ispalin(int start,int end,string &s){
        while(end>=start){
            if(s[start++]!=s[end--])return false;
        }
        return true;
    }
    int helper(int indx,string s,int n,vector<int>&dp){
        if(indx==n)return 0;
        if(dp[indx]!=-1)return dp[indx];
        int mini=INT_MAX;
        for(int i=indx;i<n;i++){
            if(ispalin(indx,i,s)){
                int temp=1+helper(i+1,s,n,dp);
                mini=min(mini,temp);
            }
        }
        return dp[indx]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return helper(0,s,n,dp)-1;
        
    }
};