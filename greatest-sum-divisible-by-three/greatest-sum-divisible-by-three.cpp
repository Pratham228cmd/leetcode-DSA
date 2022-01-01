class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
     vector<int>dp{0,0,0};
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            temp=dp;
            for(auto x:dp){
                int curr=x+nums[i];
                temp[curr%3]=max(temp[curr%3],curr);
            }
            dp=temp;
        }
        return dp[0];
    }
};