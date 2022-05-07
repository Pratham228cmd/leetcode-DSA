class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int sum=0;
        mp[0]=-1;
        int rem=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(k!=0)
            rem=sum%k;
            // mp[rem]++;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem]>1)return true;
                // else continue;
            }
            else
            mp[rem]=i;
            
        }
        return false;
        
    }
};