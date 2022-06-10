// { Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
           stack<int> stak;
       int i,a,b,temp;
       
       for(i=0;i<s.size();i++){
           if(s[i]=='+')
           {
               a=stak.top();
               stak.pop();
               b=stak.top();
               stak.pop();
               temp=b+a;
               stak.push(temp);
           }
           else if(s[i]=='-')
           {
               a=stak.top();
               stak.pop();
               b=stak.top();
               stak.pop();
               temp=b-a;
               stak.push(temp);
           }
           else if(s[i]=='*')
           {
               a=stak.top();
               stak.pop();
               b=stak.top();
               stak.pop();
               temp=b*a;
               stak.push(temp);
           }
           else if(s[i]=='/')
           {
               a=stak.top();
               stak.pop();
               b=stak.top();
               stak.pop();
               temp=b/a;
               stak.push(temp);
           }
           else
           {
               stak.push(s[i]-'0');
           }
       }
       return stak.top();
       
    }
};

// { Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends