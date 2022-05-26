class Solution {
public:
    int d[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int ans=0;
         int r = grid.size();
        int c = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>> visit(n,vector(n,false));
         if(grid[0][0] == 1 || grid[r-1][c-1] == 1){
            return -1;
        }
        q.push({0,0});
        visit[0][0]=1;
        while(!q.empty()){
            int sz=q.size();
            ans++;
            for(int i=0;i<sz;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                if(x==n-1 and y==n-1)return ans;
                for(int j=0;j<8;j++){
                    int x1 = x + d[j][0];
                    int y1 = y + d[j][1];
                    if(x1 >= 0 && x1 < r && y1 >= 0 && y1 < c){
                        if(!visit[x1][y1] && !grid[x1][y1]){
                            q.push(make_pair(x1,y1));
                            visit[x1][y1] = true;
                        }
                    }
                }
            }
            
        }
        return -1;
    }
};