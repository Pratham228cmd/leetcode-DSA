// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        
        int n=s.size();
        stack<int>st;
        int cnt=1;
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='D'){
                st.push(cnt);
                cnt++;
            }
            else{
                st.push(cnt);
                cnt++;
                while(st.empty()==false){
                    res+=to_string(st.top());
                    st.pop();
                }
            }
        }
        st.push(cnt);
         while(!st.empty()){
                    res+=to_string(st.top());
                    st.pop();
                }
                
                
                return res;
        
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends