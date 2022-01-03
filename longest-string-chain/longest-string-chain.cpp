class Solution {
public:
    int dp[1001];
    bool static cmp(string &s1, string &s2){
        return s2.size()>s1.size();
    }
    
    int longestStrChain(vector<string>& words) {
         memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),cmp);
        unordered_map<string,int>mp;
        int n=words.size();
        for(int i=0;i<n;i++){
            if(mp.find(words[i])==mp.end())
                mp[words[i]]=i;
        }
        int ans=0;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            if(words[i].size()>1){
                for(int j=0;j<words[i].size();j++){
                    string temp=words[i];
                    temp.erase(temp.begin()+j);
                    if(mp.find(temp)!=mp.end()){
                        dp[i]=max(dp[i],dp[mp[temp]]+1);
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};