class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> mp;
        int n=arr.size();
      for(int i=0;i<n;i++){
          if(mp.find(arr[i]-diff)!=mp.end()){
              mp[arr[i]]=mp[arr[i]-diff]+1;
          }
          else mp[arr[i]]=1;
      }
        int maxi=1;
        for(auto it:mp)
            maxi=max(maxi,it.second);
        
        return maxi;
    }
};