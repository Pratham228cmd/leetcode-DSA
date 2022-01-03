class Solution {
public:
    // int min()
    
        int dp[41][41];
    int solve(int left ,int right, vector<int>&arr){
        if(left==right)return 0;
        if(dp[left][right]!=-1)return dp[left][right];
          priority_queue<int> pq(arr.begin()+left, arr.begin()+right+1);
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int prod=a*b;
        int mini=INT_MAX;
        for(int i=left;i<right;i++){
            mini=min(mini,solve(left,i,arr)+solve(i+1,right,arr));
        }
        dp[left][right]=mini+prod;
        return dp[left][right];
        
        
        
    }   
    int mctFromLeafValues(vector<int>& arr) {
        memset(dp,-1,sizeof(dp));
        return solve(0,arr.size()-1,arr);
    }
};