// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
	public:
	vector<string>res;
	void helper(string s,int indx){
	    if(indx==s.size()){
	        res.push_back(s);
	        return;
	    }
	    if(s[indx]=='?'){
	        s[indx]='0';
	        helper(s,indx+1);
	        s[indx]='1';
	        helper(s,indx+1);
	    }
	    else helper(s,indx+1);
	}
		vector<string> generate_binary_string(string s)
		{
		    // Code here
		    helper(s,0);
		    return res;
		    
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends