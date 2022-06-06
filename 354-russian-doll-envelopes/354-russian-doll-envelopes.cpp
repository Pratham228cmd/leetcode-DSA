class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b)
    {   if(a[0]==b[0])return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& arr) {
        int n=arr.size();
         vector<int> dp;
        sort(arr.begin(),arr.end(),cmp);
        for(auto x:arr){
            auto indx=lower_bound(dp.begin(),dp.end(),x[1])-dp.begin();
            if(indx>=dp.size())dp.push_back(x[1]);
            else{
                dp[indx]=x[1];
            }
        }
        return dp.size();
       
    }
};