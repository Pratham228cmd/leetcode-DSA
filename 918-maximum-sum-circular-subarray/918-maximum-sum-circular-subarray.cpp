class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)sum+=nums[i];
        int mini=nums[0];
        int maxi=nums[0],curr_min=nums[0],curr_max=nums[0];
        for(int i=1;i<n;i++){
           curr_max=max(curr_max+nums[i],nums[i]);
            maxi=max(maxi,curr_max);
            
            curr_min=min(curr_min+nums[i],nums[i]);
            mini=min(mini,curr_min);
        }
        if(mini==sum)return maxi;
       return max(maxi,sum-mini);
        
        
    }
};