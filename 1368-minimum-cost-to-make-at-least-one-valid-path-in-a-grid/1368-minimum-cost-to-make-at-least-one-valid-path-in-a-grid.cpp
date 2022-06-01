class Solution {
public:
     bool valid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector <vector <int>> dp(m, vector <int>(n, INT_MAX));
        dp[0][0]=0;
        deque<pair<int,int>>q;
        q.push_back({0,0});
       int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while(!q.empty()){
            auto temp=q.front();
            q.pop_front();
            int x=temp.first;
            // int y=temp.second;
           
            int y=temp.second;
             int wt=grid[x][y];
            for(int k=0;k<4;k++){
                int xx=x+dx[k];
                int yy=y+dy[k];
                int val=1;
                if(k+1==wt)
                    val=0;
                if(valid(xx,yy,m,n)==true){
                    if(val+dp[x][y]<dp[xx][yy]){
                        
                        dp[xx][yy]=dp[x][y]+val;
                        if(val==0){
                            q.push_front({xx,yy});
                            
                        }
                        else q.push_back({xx,yy});
                        
                    }
                    
                }
                
            }
        }
        return dp[m-1][n-1];
        
    }
};