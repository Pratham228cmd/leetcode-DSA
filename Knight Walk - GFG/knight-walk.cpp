// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:
 int xarr[8]={-1,-2,-2,-1,1,2, 2, 1};
    int yarr[8]={2,1,-1,-2,2,1, -1, -2};
	int minStepToReachTarget(vector<int>&start, vector<int>&end, int n){
	    // Code here
	   // vector<vector<bool>>visit(n,vector(n,false));
	    int visit[n+1][n+1]={0};
	    queue<pair<int,int>>q;
	    int ans=0;
	    q.push({start[0],start[1]});
	    visit[start[0]][start[1]]=1;
	    while(!q.empty()){
	       int sz=q.size();
	       
	      
	       for(int i=0;i<sz;i++){
	           int x=q.front().first;
	           int y=q.front().second;
	           if(x==end[0] and y==end[1])return ans;
	           q.pop();
	           //ans++;
	           for(int i=0;i<8;i++){
	               int x1=x+xarr[i];
	               int y1=y+yarr[i];
	               if(x1>=1 and y1>=1 and x1<=n and y1<=n){
	                   if(visit[x1][y1]!=1){
	                       visit[x1][y1]=1;
	                       q.push({x1,y1});
	                       
	                   }
	               }
	           }
	       }
	       ans++;
	        
	    }
	    return -1;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends