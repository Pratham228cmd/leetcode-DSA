class Solution {
public:
    int n;
    int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
    vector<pair<int,int>>v1,v2;
    void dfs(vector<vector<int>>&vis,int i,int j,vector<vector<int>>&grid,int num){
        vis[i][j]=1;
        if(num==0)v1.push_back({i,j});
        else v2.push_back({i,j});
        
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=n || y>=n || x<0 || y<0)continue;
            if(vis[x][y]==0 and grid[x][y]==1)dfs(vis,x,y,grid,num);
        }
        
        
        
    }
    int shortestBridge(vector<vector<int>>& grid) {
         n=grid.size();
        int num=0;
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 and grid[i][j]==1){
                    dfs(vis,i,j,grid,num);
                num++;}
                
            }
        }
        int ans=INT_MAX;
        for(auto a:v1){
            for(auto b:v2){
                ans=min(ans,abs(a.first-b.first)+abs(a.second-b.second));
            }
        }
        return ans-1;
    }
};