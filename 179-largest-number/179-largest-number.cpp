class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        for(int i=0;i<n;i++){
             if(ans=="" and nums[i]==0){
                continue;
             }
             ans+=to_string(nums[i]);
        }
        return ans == "" ? "0" : ans;
        
        
    }
    static bool cmp(int a,int b){
        string x = to_string(a), y = to_string(b);
        string s1 = x+y, s2 = y+x;
        return s1>s2;
    }
};