class Solution {
public:
    int maxHeight(vector<vector<int>>& arr) {
        int n=arr.size();
        for(auto &x:arr)
            sort(x.begin(),x.end());
        sort(arr.begin(),arr.end());
        vector<int>dp(n);
        for(int i=0;i<n;i++){
            dp[i]=arr[i][2];
            for(int j=0;j<i;j++){
                if(arr[j][1]<=arr[i][1] and arr[i][2]>=arr[j][2]){
                    dp[i]=max(dp[i],dp[j]+arr[i][2]);
                }
            }
        }
        
         return *max_element(dp.begin(),dp.end());
        
    }
};