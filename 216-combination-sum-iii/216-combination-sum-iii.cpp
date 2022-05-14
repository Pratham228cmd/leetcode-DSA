class Solution {
public:
    vector<vector<int>> res;
    void helper(int k,int n,int indx,vector<int>&temp){
        if(temp.size()==k){
            if(n==0)res.push_back(temp);
            return;
        }
        if(n<0)return;
        for(int i=indx;i<=9;i++){
            temp.push_back(i);
            helper(k,n-i,i+1,temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>temp;
        helper(k,n,1,temp);
        return res;
    }
};