class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return -1;
        int max_ending=nums[0],min_ending=nums[0],res=nums[0];
        for(int i=1;i<n;i++){
            int temp=max_ending;
            max_ending=max({max_ending*nums[i],min_ending*nums[i],nums[i]});
            min_ending=min({temp*nums[i],min_ending*nums[i],nums[i]});
            res=max(res,max_ending);    
        }
        return res;
        
        
        
        
    }
};