class Solution {
public:
    int m,n;
    bool visit[302][302];
    void helper(int i,int j,vector<vector<char>>& grid){
        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]=='0' || visit[i][j]==1)return;
        visit[i][j]=1;
        helper(i+1,j,grid);
        helper(i,j+1,grid);
        helper(i-1,j,grid);
        helper(i,j-1,grid);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        memset(visit,false,sizeof(visit));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' and visit[i][j]==0){
                    helper(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};