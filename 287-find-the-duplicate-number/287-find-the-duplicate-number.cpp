class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=0,fast=0;
        while(1){
           
            slow=nums[slow];
            fast=nums[nums[fast]];
             if(slow==fast)break;
        }
        int find=0;
        while(slow!=find){
            slow=nums[slow];
            find=nums[find];
        }
        return find;
        
        
       
        
    }
};