// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{
//Your code here

    int sum=arr[0];
    int ans=0,res=0;
    for(int i=1;i<n;i++){
    sum+=arr[i];
    ans+=i*arr[i];}
    res=ans;
    for(int i=0;i<n-1;i++){
        ans=ans+sum-n*arr[n-1-i];
        res=max(res,ans);
    }
    return res;
    
    
    
}