// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++
#define MAX 5
class Solution{
    public:
    int visit[6][6];
    vector<string>res;
    bool check(int x,int y,int n,vector<vector<int>> &m){
    if(x>=n||x<0||y>=n||y<0||m[x][y]==0||visit[x][y]==1)
    return false;
    return true;
}
    void helper(vector<vector<int>> &m, int n,int i,int j,string temp){
        if(i==n-1 and j==n-1 and m[i][j]==1){
            res.push_back(temp);
            return;
        }
        visit[i][j]=1;
        if(check(i+1,j,n,m)==1){
            temp.push_back('D');
            helper(m,n,i+1,j,temp);
            temp.pop_back();
        }
        if(check(i-1,j,n,m)==1){
            temp.push_back('U');
            helper(m,n,i-1,j,temp);
            temp.pop_back();
        }
        if(check(i,j-1,n,m)==1){
            temp.push_back('L');
            helper(m,n,i,j-1,temp);
            temp.pop_back();
        }
        if(check(i,j+1,n,m)==1){
            temp.push_back('R');
            helper(m,n,i,j+1,temp);
            temp.pop_back();
        }
        visit[i][j]=0;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0)return res;
        memset(visit,0,sizeof(visit));
        string temp;
        helper(m,n,0,0,temp);
        return res;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends