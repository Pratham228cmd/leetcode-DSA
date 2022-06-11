// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        vector <pair<int,int>> dir {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int m=grid.size(),n=grid[0].size();
         int fresh=0; //To keep track of all fresh oranges left
         queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto temp=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int i=temp.first+dir[k].first;
                    int j=temp.second+dir[k].second;
                    if(i>=0 and j>=0 and i<m and j<n and grid[i][j]==1){
                        q.push({i,j});
                        grid[i][j]=2;
                        fresh--;
                    }
                    
                }
            }
            ans++;
        }
         if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends