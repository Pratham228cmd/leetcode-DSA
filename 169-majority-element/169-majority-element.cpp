class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=1;
        int ans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==ans)cnt++;
            else cnt--;
            if(cnt==0){
                cnt=1;
                ans=nums[i];
            }
        }cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ans)cnt++;
        }
        if(cnt>n/2)return ans;
        return -1;
    }
};