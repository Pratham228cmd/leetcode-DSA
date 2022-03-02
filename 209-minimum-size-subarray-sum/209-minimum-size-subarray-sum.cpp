class Solution {
public:
    int minSubArrayLen(int x, vector<int>& nums) {
                int n=nums.size();
        int sum=0;
        int len = INT_MAX;
        int s=0;
        int e=0;
        bool flag=false;
        while(e<n){
            sum+=nums[e++];
            while(sum>=x){
                len=min(len,e-s);
                sum-=nums[s++];
            }
            
        }
          return len == INT_MAX ? 0 : len;
    }
};