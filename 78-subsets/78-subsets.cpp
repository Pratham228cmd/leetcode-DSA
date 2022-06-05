class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& nums,vector<int>temp,int indx){
        if(indx==nums.size()){
            res.push_back(temp);
            return;
        }
        helper(nums,temp,indx+1);
        temp.push_back(nums[indx]);
        helper(nums,temp,indx+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        helper(nums,temp,0);
        return res;
    }
};