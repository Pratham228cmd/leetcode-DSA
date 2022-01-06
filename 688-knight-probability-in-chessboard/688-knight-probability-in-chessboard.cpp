class Solution {
public:
     int dx[8]={-1,-1,-2,-2,1,1,2,2};
    int dy[8]={2,-2,1,-1,2,-2,1,-1};
    // double dp[26][26][101];
    vector<vector<vector<double>>> dp;
    double solve(int r,int c,int n,int k){
        if(r<0 || c<0 || r>=n || c>=n)return 0.0;
        
        if(k==0)return 1.0;
        if(dp[r][c][k]!=-1)return dp[r][c][k];
        double sum=0;
        for(int i=0;i<8;i++){
            int x=r+dx[i];
            int y=c+dy[i];
            sum+=solve(x,y,n,k-1)/8.0;
        }
        // sum=sum/8.0;
        return dp[r][c][k]=sum;
        
        
    }
    double knightProbability(int n, int k, int r, int c) {
        // memset(dp,-1.0,sizeof(dp));
        dp=vector<vector<vector<double>>>(26,vector<vector<double>>(26,vector<double>(101,-1)));
        return solve(r,c,n,k);
    }
};