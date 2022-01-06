#define ll long long 
class Solution {
public:
    int n,m;
     int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    ll dp[51][51][51];
    int helper(int r,int c,int move,int m,int n){
        if(move<=-1)return 0;
        if(r<0 || c<0 || r>=m || c>=n)return 1;
        // if(move<=0)return 0;
        if(dp[r][c][move]!=-1)return dp[r][c][move];
        ll ans=0;
        for(int i=0;i<4;i++){
            // dp[]
             ans=(ans+helper(r+dx[i],c+dy[i],move-1,m,n))%1000000007 ;
        }
      return dp[r][c][move]=ans;
        
        
        
    }
    int findPaths(int m, int n, int move, int r, int c) {
        // this->m=m;
        // this->n=n;
        memset(dp,-1,sizeof(dp));
        return helper(r,c,move,m,n);
         
        
    }
};