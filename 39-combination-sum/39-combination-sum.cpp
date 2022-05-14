class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>&arr, int target,int indx,vector<int>&temp,int n){
        if(target==0){
            res.push_back(temp);
            return;
        }
        if(target<0)return;
        for(int i=indx;i<n;i++){
            temp.push_back(arr[i]);
            helper(arr,target-arr[i],i,temp,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>&arr, int target) {
        int n=arr.size();
        vector<int>temp;
        // sort(arr.begin(),arr.end());
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        helper(arr,target,0,temp,n);
        return res;
    }
};