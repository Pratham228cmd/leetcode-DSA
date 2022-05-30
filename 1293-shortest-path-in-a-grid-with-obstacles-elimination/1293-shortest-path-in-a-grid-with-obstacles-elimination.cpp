class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int limit) {
         int n = grid.size();
        
        int m = grid[0].size();
        
        vector<int> dx = {-1, 0, 1, 0};
        
        vector<int> dy = {0, 1, 0, -1};
        
        vector<vector<int>> obstacle(n, vector<int> (m, 0));
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        
        queue<vector<int>> q;
        
        q.push({0, 0, grid[0][0]});
        
        obstacle[0][0] = grid[0][0];
        
        vis[0][0] = true;
        
        int steps = 0;
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                auto curr_cell = q.front();
                
                q.pop();
                
                int x = curr_cell[0];
                
                int y = curr_cell[1];
                
                int curr_obstacle = curr_cell[2];
                
                if(x == n - 1 && y == m - 1)
                {
                    return steps;
                }
                
                for(int k = 0; k < 4; k++)
                {
                    int new_row = x + dx[k];
                    
                    int new_col = y + dy[k];
                    
                    if(new_row >= 0 && new_row < n && new_col >= 0 && new_col < m)
                    {
                        int old_obstacle = obstacle[new_row][new_col];
                
                        int new_obstacle = curr_obstacle + grid[new_row][new_col];
                        
                        if((vis[new_row][new_col] == false) && new_obstacle <= limit)
                        {
                            q.push({new_row, new_col, new_obstacle});
                            
                            obstacle[new_row][new_col] = new_obstacle;
                            
                            vis[new_row][new_col] = true;
                        }
                        
                        else if(new_obstacle < old_obstacle && new_obstacle <= limit)
                        {
                            q.push({new_row, new_col, new_obstacle});
                            
                            obstacle[new_row][new_col] = new_obstacle;
                            
                            vis[new_row][new_col] = true;
                        }
                    }
                }
            }
            
            steps++;
        }
        
        return -1;
    
    }
};