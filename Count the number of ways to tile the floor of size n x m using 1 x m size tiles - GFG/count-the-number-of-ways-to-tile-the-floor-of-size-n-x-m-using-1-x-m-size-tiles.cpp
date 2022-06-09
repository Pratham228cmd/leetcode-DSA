// { Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	public:
		int countWays(int n, int m)
	{
	    // Code here.
	    vector<int>dp(n+1,1);
	    for(int i=m;i<=n;i++){
	        dp[i]=(dp[i-m]+dp[i-1])%1000000007;
	    }
	    return dp[n]%1000000007;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.countWays(n, m);
		cout << ans <<"\n";
	}  
	return 0;
}  // } Driver Code Ends