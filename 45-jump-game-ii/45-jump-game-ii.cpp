class Solution {
public:
    int jump(vector<int>& nums) {
         if(nums.size()<3)
            return (nums.size()==1)?0:1;
       int n=nums.size();
        int ans=1;
        int maxreach=0,currreach=0;
        int i=0;
        while(i<n-1){
            currreach=max(i+nums[i++],maxreach);
            maxreach=currreach;
            if(maxreach>=n-1)return ans;
            while(i<currreach){
                maxreach=max(maxreach,i+nums[i++]);
                if(maxreach>=n-1)return ++ans;
            }
            ans++;
        }
        return ans;
    }
};