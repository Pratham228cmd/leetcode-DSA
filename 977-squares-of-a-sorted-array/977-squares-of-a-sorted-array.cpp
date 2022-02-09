class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        int l=0,r=n-1;
        for(int k=n-1;k>=0;k--){
            if(abs(nums[l])<abs(nums[r])){
               arr[k]=nums[r]*nums[r];
                r--;
            }
            else{
                arr[k]=nums[l]*nums[l];
                l++;
            }
        }
        return arr;
    }
};