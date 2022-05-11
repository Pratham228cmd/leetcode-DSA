class Solution {
public:
    int maximumDifference(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return -1;
        int ans=-1;
        if(arr[1]>arr[0])ans=arr[1]-arr[0];
        int mini=arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]-mini>ans){
                ans=arr[i]-mini;
            }
            if(arr[i]<mini)
                mini=arr[i];
        }
       return ans == 0 ? -1 : ans;
    }
};