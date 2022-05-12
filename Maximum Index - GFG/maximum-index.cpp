// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxIndexDiff(int arr[], int n) {
        // code here
        vector<int>left(n),right(n);
        left[0]=arr[0];
        for(int i=1;i<n;i++){
            left[i]=min(left[i-1], arr[i]);
        }
        right[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],arr[i]);
        }
        int diff=INT_MIN;
        int i=0,j=0;
        while(i<n and j<n){
            if(right[j]>=arr[i]){
                diff=max(j-i,diff);
                j++;
            }
            else i++;
        }
        return diff;
    }

};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.maxIndexDiff(a, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends