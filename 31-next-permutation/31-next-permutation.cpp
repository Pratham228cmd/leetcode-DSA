class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1])
                break;
        }
        if(i==-1){
            sort(nums.begin(),nums.end());
                return;
        }
        sort(nums.begin()+i+1,nums.end());
        int j=i+1;
        
    while(j<n && nums[j]<=nums[i]){
            j++;
        }
            
        swap(nums[i], nums[j]);
        return;
        
    }
   
};