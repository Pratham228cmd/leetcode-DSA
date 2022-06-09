// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	#define ll long long
	ll countStrings(int n) {
	    // code here
	     long prev0 = 1l, prev1 = 1l;
	     for(int i=2;i<=n;i++){
	         ll cur0=prev1%1000000007;
	         ll cur1=(prev1+prev0)%1000000007;
	         prev0=cur0;
	         prev1=cur1;
	         
	     }
	       return (prev0+prev1)% 1000000007;
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends