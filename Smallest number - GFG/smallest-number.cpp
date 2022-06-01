// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string smallestNumber(int S, int D){
        // code here 
        string ans="";
        if(S>D*9)return "-1";
        int res[D]={0};
        res[0]=1;
        S--;
        int i=D-1;
        while(i>=1 and S){
            res[i]=min(9,S);
            S-=res[i];
            i--;
        }
        if(S>0)res[0]+=S;
        for(int i=0; i<D; i++){
            if(res[i]>9)return "-1";
            ans.push_back('0'+res[i]);
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   // } Driver Code Ends