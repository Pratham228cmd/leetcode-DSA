class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int res=nums[n-1]-nums[0];
        int left=nums[0]+k,right=nums[n-1]-k;
        for(int i=0;i<n-1;i++){
            int maxi=max(nums[i]+k,right),mini=min(left,nums[i+1]-k);
            res=min(res,maxi-mini);
        }
        return res;
    }
};