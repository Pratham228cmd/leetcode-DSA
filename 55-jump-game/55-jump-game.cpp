class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int n=;
        // vector<int>dp(n,1);
        int i=0,maxi=0;
        while(i<nums.size() and i<=maxi){
            maxi=max(maxi,i+nums[i]);
            i++;
        }
        return i==nums.size();
        
    }
};