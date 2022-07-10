class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0] = nums[0];
        deque<int>dq;
        dq.push_back(0);
        for(int i=1;i<n;i++){
            if(dq.front()+k<i)dq.pop_front();
            nums[i]=nums[i]+nums[dq.front()];
            while(!dq.empty() and nums[dq.back()]<nums[i])
                dq.pop_back();
            
            dq.push_back(i);
        }
        return nums.back();
        
    }
};