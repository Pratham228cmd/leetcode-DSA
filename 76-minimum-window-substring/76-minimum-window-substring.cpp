class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m>n)return "";
        map<char,int>mp,temp;
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int cnt=0,start=0,start_indx=-1,ans=INT_MAX;
        for(int i=0;i<n;i++){
            temp[s[i]]++;
            if(mp[s[i]]>=temp[s[i]])cnt++;
            if(cnt==m){
                while(temp[s[start]]>mp[s[start]] || mp[s[start]]==0){
                    if(temp[s[start]]>mp[s[start]])temp[s[start]]--;
                    start++;
                }
                int min_len=i-start+1;
                if(min_len<ans){
                    ans=min_len;
                    start_indx=start;
                }
            }
        }
         if(start_indx==-1)
            return "";
        return s.substr(start_indx,ans);
    }
};