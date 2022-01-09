class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int  mini=INT_MAX,ans=0;
        for(int i=0;i<arr.size();i++){
            if(mini>arr[i]) mini=arr[i];
            else if(arr[i]-mini>ans) ans=arr[i]-mini;
        }
        return ans;
    }
};