class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n=nums.size();
        int res=0;
        int prevres=0;
        int i=0,j=0;
        while(j<n){
            if(nums[j]>=left and nums[j]<=right){
                prevres=j-i+1;
                res+=j-i+1;
            }
            else if(nums[j]<left){
                res+=prevres;
            }
            else{
                prevres=0;
                i=j+1;
            }
            j++;
        }
        return res;
    }
};