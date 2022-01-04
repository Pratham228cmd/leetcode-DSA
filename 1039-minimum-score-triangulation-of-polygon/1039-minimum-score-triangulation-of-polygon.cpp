class Solution {
public:
    int dp[50][50];
    int mcm(vector<int>&arr,int left,int right){
        if(right<=left+1)return 0;
        if ( dp[left][right] != -1 ) return dp[left][right];
        int res=INT_MAX;
        for(int i=left+1;i<right;i++){
            res=min(res,arr[i]*arr[left]*arr[right]+mcm(arr,left,i)+mcm(arr,i,right));
        }
        return dp[left][right]=res;
    }
    int minScoreTriangulation(vector<int>& values) {
         memset(dp, -1, sizeof(dp));
        int n = values.size();
        int ans = mcm(values, 0, n-1);
        return ans;
    }
};