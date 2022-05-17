// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	 vector<int> C(128);
    for (char ch: A) C[ch]++;
    for (char ch: B) C[ch]--;
    for (int i = 0; i < 128; i++) if (C[i]) return -1;
	int i = A.size() - 1, j = B.size() - 1, count = 0;
	while (i >= 0) {
	    if (A[i] == B[j]) j--;
	    else count++;
	    i--;
	}
	return count;
    	
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends