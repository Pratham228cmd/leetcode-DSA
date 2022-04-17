class Solution {
public:
    vector<int>adj[100001];
    int ans;
    int dfs(vector<int>& par, string &s,int src,int parent){
        int maxi=0;
        int secmaxi=0;
        for(auto x:adj[src]){
            if(x==parent)continue;
             int temp=dfs(par,s,x,src);
            if(s[src]==s[x])continue;
            if(temp>=maxi){
                secmaxi=maxi;
                maxi=temp;
            }
           else if(temp>=secmaxi){
                secmaxi=temp;
            }
        }
        ans=max(ans,maxi+secmaxi+1);
        return maxi+1;
    }
    int longestPath(vector<int>& par, string s) {
        int n=s.size();
        for(int i=1;i<n;i++){
            adj[par[i]].push_back(i);
            adj[i].push_back(par[i]);
        }
        dfs(par,s,0,-1);
        return ans;
    }
};